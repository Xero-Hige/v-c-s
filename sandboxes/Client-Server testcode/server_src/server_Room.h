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
	unsigned limit; //max clients
	vector<ClientHandler *> clients;
	bool active;
	bool currently_playing;

public:
	unsigned long id; //room id

	Room(unsigned limit, unsigned long r_id = 0);
	bool addClient(ClientHandler* ch);
	bool exitRoom(ClientHandler* ch);
	bool isPlaying();
	bool isFull();
	bool isActive();
	virtual ~Room();
};

} /* namespace std */
#endif /* ROOM_H_ */
