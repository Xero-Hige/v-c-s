/*
 * Lobby.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef LOBBY_H_
#define LOBBY_H_

#include <map>
#include "Room.h"
#include "RoomKiller.h"

class Lobby{
	friend class MatchMakingStrategy;
	std::map<unsigned long,Room*> rooms;
	RoomKiller room_killer;

public:
	Lobby();
	void addClient(ClientHandler * ch); //usar solo cuando es un cliente viejo, que
										//viene de otro room, ya que no inicia el
										//thread
	void addNewClient(ClientHandler * ch); //Usar solo cuando es un nuevo cliente
	virtual ~Lobby();
};

#endif /* LOBBY_H_ */
