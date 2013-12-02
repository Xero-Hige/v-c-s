/*
 * MsgInterpreter.cpp
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#include "ClientMsgInterpreter.h"
#include "../backend/backend.h"
#include "../../libs/messages/MsgConstants.h"
#include "../../libs/game_messages/message_reader.h"
#include "../../libs/game_messages/game_message_reader.h"
#include "../../libs/boards/product.h"
#include "../../libs/combination_effects/combination_effect.h"

#include <string>
#include <list>
#include <stdio.h>

using std::string;
using std::list;

ClientMsgInterpreter::ClientMsgInterpreter(Server_Connector* c, Backend * b) {
	this->client = c;
	this->backend = b;
}

void ClientMsgInterpreter::exitRoom(){
	//Enviar el nuevo room, el server lo saca del room actual solo.
	client->enterRoom();
}

void ClientMsgInterpreter::interpretParticularMsg(string msg){
    msg_reader.processNewMessage(msg);
    string header = msg_reader.getMessageHeader();
    if (header == SCORE_UPDATE) {
        string user_id;
        int score;
        game_msg_reader.readScoreUpdateMsg(user_id, score, msg_reader);
        backend->addToPlayerScore(user_id, score);
    } else if (header == GAME_OVER) {
        //TODO
    } else if (header == COMBINATION_EFFECTS) {
        list<CombinationEffect*> effects;
        game_msg_reader.readCombinationEffectsMsg(effects, msg_reader);
        backend->addEffectsToQueue(effects);
    } else if (header == PRODUCT_REFILL) {
        int column;
        list<Product*> products;
        game_msg_reader.readProductRefill(column,products,msg_reader);
        backend->addRefillerProducts(column, products);
    }
}

void ClientMsgInterpreter::manageLevel(){
	std::cout << "Cliente recibe datos del nivel" << std::endl;
	std::string level_data;
	client->recvMsg(level_data);
	client->setLevel(level_data);
}

void ClientMsgInterpreter::exitCharPressed(){
	client->exitCharPressed();
}

void ClientMsgInterpreter::closeConnection(){
	client->closeConnection();
}

ClientMsgInterpreter::~ClientMsgInterpreter() {
	// TODO Auto-generated destructor stub
}
