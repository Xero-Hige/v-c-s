/*
 * Room.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "server_Room.h"
#include <iostream>

namespace std {

unsigned long Room::id_counter = 0;

Room::Room(unsigned limit) {
	// TODO Auto-generated constructor stub
	this->id = Room::id_counter;
	Room::id_counter++;
	this->limit = limit;

}

bool Room::addClient(ClientHandler* ch){
	if (this->clients.size() >= limit) return false;
	cout << "Se agrego un cliente al room " << this->id;
	cout << endl;
	clients.push_back(ch);
	ch->setRoom(this);
	ch->start();
	return true;
}

bool Room::exitRoom(ClientHandler* ch){
	for (vector<ClientHandler*>::iterator it = clients.begin(); it < clients.end(); it++){
		ClientHandler* actual_ch = *it;
		if (ch == actual_ch){//si los ptrs son iguales
			clients.erase(it);
			cout << "El cliente salio del room" << endl;
			return true;
		}
	}
	return false;
}

bool Room::isFull(){
	return (this->clients.size() >= limit);
}

Room::~Room() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
