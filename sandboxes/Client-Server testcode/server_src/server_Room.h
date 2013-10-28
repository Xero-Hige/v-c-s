/*
 * Room.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef ROOM_H_
#define ROOM_H_

#include "server_ClientHandler.h"
#include <vector>

namespace std {

class Room {
	static unsigned long id_counter; //Generador de un id incremental
	unsigned long id;
	unsigned limit; //max players
	vector<ClientHandler *> clients;

public:
	Room(unsigned limit);
	bool addClient(ClientHandler* ch);
	bool exitRoom(ClientHandler* ch);
	bool isFull();
	virtual ~Room();
};

} /* namespace std */
#endif /* ROOM_H_ */
