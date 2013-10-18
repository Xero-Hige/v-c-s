/*
 * Lobby.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "server_Lobby.h"
#include "server_Room.h"

namespace std {

Lobby::Lobby() {
	// TODO Auto-generated constructor stub

}

void Lobby::addClient(ClientHandler * ch) {
	m.lock();
	//Si no hay ningun room creado o si el ultimo room esta lleno...
	if (this->rooms.size() == 0 || this->rooms.back()->isFull()){
		Room * new_room = new Room(1);
		new_room->addClient(ch);
		rooms.push_back(new_room);
	} else {
		//Si no esta lleno y hay alguno creado...
		this->rooms.back()->addClient(ch);
	};
	m.unlock();
}

Lobby::~Lobby() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
