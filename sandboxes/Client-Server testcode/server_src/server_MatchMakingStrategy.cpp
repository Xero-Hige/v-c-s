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
	string s_roomid;
	ch->recvMsg(s_roomid);
	unsigned long room_id = atoi(s_roomid.c_str());
	// .at crea un nuevo pointer si no existe el room pedido
	Room * actual_room = lob->rooms[room_id];
	if(!actual_room){ //si no existe el id creo el room pedido
		Room * new_room = new Room(2, room_id);
		new_room->addClient(ch);
		lob->rooms.insert(map_pair(room_id, new_room)); //piso el anterior
		return;
	}
	else if (actual_room->isFull() || actual_room->isPlaying())
		return addDefault(lob, ch);
	else actual_room->addClient(ch);
}

void MatchMakingStrategy::addDefault(Lobby * lob, ClientHandler * ch){
	//Si ya hay un room creado itera e inserta en alguno vacio.
	if (lob->rooms.size() != 0){
		map<unsigned long, Room*>::iterator it = lob->rooms.begin();
		for (; it != lob->rooms.end(); it++){
			if (! it->second->isFull()){
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
