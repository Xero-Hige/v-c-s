/*
 * MatchMakingStrategy.cpp
 *
 *  Created on: 24/10/2013
 *      Author: juan
 */

#include "server_MatchMakingStrategy.h"
#include <iostream>

namespace std {

MatchMakingStrategy::MatchMakingStrategy() {
}

void MatchMakingStrategy::addClient(Lobby * lob, ClientHandler * ch){
	string s;
	ch->recvMsg(s);//matchmaking message
	if (!s.compare(MM_USER_DEF)) //==0
		addUserDefined(lob, ch);
	else if (!s.compare(MM_DEFAULT)) //==0
		addDefault(lob, ch);
}

void MatchMakingStrategy::addUserDefined(Lobby * lob, ClientHandler * ch){
	string room_id;
	ch->recvMsg(room_id);
	unsigned index = atoi(room_id.c_str());
	if (index >= lob->rooms.size()) return addDefault(lob, ch);
	Room * actual_room = lob->rooms.at(index);
	if (actual_room->isFull()) return addDefault(lob, ch);
	actual_room->addClient(ch);
}

void MatchMakingStrategy::addDefault(Lobby * lob, ClientHandler * ch){
	//Si no hay ningun room creado o si el ultimo room esta lleno...
		if (lob->rooms.size() == 0 || lob->rooms.back()->isFull()){
			Room * new_room = new Room(2);
			new_room->addClient(ch);
			lob->rooms.push_back(new_room);
		} else {
			//Si no esta lleno y hay alguno creado...
			lob->rooms.back()->addClient(ch);
		}
}

MatchMakingStrategy::~MatchMakingStrategy() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
