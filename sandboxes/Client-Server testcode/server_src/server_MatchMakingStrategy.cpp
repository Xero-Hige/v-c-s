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
	if (!s.compare(MM_USER_DEF))
		addUserDefined(lob, ch);
	else if (!s.compare(MM_DEFAULT))
		addDefault(lob, ch);
}

void MatchMakingStrategy::addUserDefined(Lobby * lob, ClientHandler * ch){
	string s_roomid;
	ch->recvMsg(s_roomid);
	unsigned long room_id = atoi(s_roomid.c_str());
	map<unsigned long, Room*>::iterator it;
	it = lob->rooms.find(room_id); //intenta encontrar la key
	if (it == lob->rooms.end()){//Si no la encontro no existe un room con ese id...
		Room * new_room = new Room(2, room_id);
		new_room->addClient(ch);
		lob->rooms.insert(map_pair(room_id, new_room));
		return;
	}
	//Si lo encontro...
	else if (it->second->isFull() || it->second->isPlaying())
				return addDefault(lob, ch);
	else it->second->addClient(ch);
}

void MatchMakingStrategy::addDefault(Lobby * lob, ClientHandler * ch){
	//Si ya hay un room creado itera e inserta en alguno vacio.
	if (lob->rooms.size() != 0){
		map<unsigned long, Room*>::iterator it;
		for (it = lob->rooms.begin(); it != lob->rooms.end(); it++){
			if (! it->second->isFull()){
				cout << "ESTOY EN LA DEFAULT" << endl;
				it->second->addClient(ch);
				return;
			}
		}
	}
	//Si no hay uno creado o si no pudo insertar en uno vacio crea uno nuevo
	Room * new_room = new Room(2);
	new_room->addClient(ch);
	lob->rooms.insert( map_pair(new_room->id,new_room));
}

MatchMakingStrategy::~MatchMakingStrategy() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
