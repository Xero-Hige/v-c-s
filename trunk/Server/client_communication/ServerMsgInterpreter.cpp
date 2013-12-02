/*
 * MsgInterpreter.cpp
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#include "ServerMsgInterpreter.h"
#include "../../libs/messages/MsgConstants.h"
#include "../../libs/game_messages/game_message_reader.h"
#include "../../libs/game_messages/message_reader.h"
#include "../../libs/game_messages/game_msg_constants.h"

#include <string>
#include <iostream>

using std::string;

ServerMsgInterpreter::ServerMsgInterpreter(ClientHandler* c) {
	this->client = c;
}

void ServerMsgInterpreter::exitRoom(){
	client->exitRoom();
}

void ServerMsgInterpreter::closeConnection(){
	client->closeConnection();
}

void ServerMsgInterpreter::exitCharPressed(){
	//todo cortar comunicacion con el user.
}

void ServerMsgInterpreter::manageLevel(){
	std::cout << "Servidor envia datos del nivel." << std::endl;
	client->sendLevelData();
}

void ServerMsgInterpreter::interpretParticularMsg(std::string msg){
	msg_reader.processNewMessage(msg);
	string header = msg_reader.getMessageHeader();
	if (header == SWAP) {
	    string user_id;
	    Position position1, position2;
	    game_msg_reader.readSwapMessage(user_id, position1, position2, msg_reader);
	    client->swapMade(position1, position2);
	}
}

ServerMsgInterpreter::~ServerMsgInterpreter() {
}
