/*
 * Lobby.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef LOBBY_H_
#define LOBBY_H_

#include <map>
#include "server_Room.h"
#include "server_RoomKiller.h"

namespace std {

class Lobby{
	friend class MatchMakingStrategy;
	map<unsigned long,Room*> rooms;
	RoomKiller room_killer;

public:
	Lobby();
	void addClient(ClientHandler * ch); //Usar solo cuando es un nuevo cliente
	virtual ~Lobby();
};

} /* namespace std */
#endif /* LOBBY_H_ */
