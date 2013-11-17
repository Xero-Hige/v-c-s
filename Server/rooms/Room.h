/*
 * Room.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef ROOM_H_
#define ROOM_H_

#include "../client_communication/ClientHandler.h"
#include <vector>

class Room {
	unsigned limit; //max clients
	Lobby * lob;
	std::vector<ClientHandler *> clients;
	bool active;
	bool currently_playing;

public:
	static unsigned long id_counter; //Generador de un id incremental
	unsigned long id; //room id

	Room(Lobby * lob, unsigned limit, unsigned long r_id = 0);
	bool addClient(ClientHandler* ch);
	bool exitRoom(ClientHandler* ch);
	void notifyClients(std::string msg);
	bool isPlaying();
	bool isFull();
	bool isActive();
	virtual ~Room();
};

#endif /* ROOM_H_ */
