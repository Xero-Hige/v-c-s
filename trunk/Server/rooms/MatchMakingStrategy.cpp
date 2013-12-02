/*
 * MatchMakingStrategy.cpp
 *
 *  Created on: 24/10/2013
 *      Author: juan
 */

#include "MatchMakingStrategy.h"
#include "../client_communication/ClientHandler.h"
#include <iostream>
#include <map>
#include <string>
#include "Lobby.h"
#include "Room.h"

MatchMakingStrategy::MatchMakingStrategy() {
}

void MatchMakingStrategy::addClient(Lobby * lob, ClientHandler * ch){
	std::string s;
	//ch->recvMsg(s);//matchmaking message
	//unsigned msg = atoi(s.c_str());
	if (/*msg == MM_USER_DEF*/ false)
		addUserDefined(lob, ch);
	else if (/*msg == MM_DEFAULT*/ true)
		addDefault(lob, ch);
}

void MatchMakingStrategy::addUserDefined(Lobby * lob, ClientHandler * ch){
	std::string s_roomid;
	ch->recvMsg(s_roomid);
	unsigned long room_id = atoi(s_roomid.c_str());
	Room * r = lob->getRoom(room_id);
	if (!r || r->isFull() || r->isPlaying()){
		return addDefault(lob, ch);
	} else {
		//Intenta agregarlo..
		if (!(r->addClient(ch))){
			//Si no se pudo agregar al room es porque no le da el level
			return addDefault(lob, ch);
		}
	}
}

void MatchMakingStrategy::addDefault(Lobby * lob, ClientHandler * ch){
	//Pide un room vacio y q no este jugando
	Room * r = lob->getNotFullNotPlayingRoom();
	if (!r){
		//Si no hay uno creado o si no pudo insertar en uno vacio crea uno nuevo
		lob->createRoom(ch);
	} else {
		r->addClient(ch);
	}
}

MatchMakingStrategy::~MatchMakingStrategy() {
	// TODO Auto-generated destructor stub
}
