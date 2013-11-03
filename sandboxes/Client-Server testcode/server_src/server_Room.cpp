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

Room::Room(unsigned limit, unsigned long r_id) {
	if (!r_id){
		//el id se auto-genera
		this->id = Room::id_counter;
		Room::id_counter++;
	} else {
		this->id = r_id;
	}
	this->limit = limit;
	active = true;
	currently_playing = false;
}

bool Room::addClient(ClientHandler* ch){
	if (this->clients.size() >= limit || currently_playing) return false;
	cout << "Se agrego un cliente al room " << this->id;
	cout << endl;
	clients.push_back(ch);
	ch->setRoom(this);
	return true;
}

bool Room::exitRoom(ClientHandler* ch){
	for (vector<ClientHandler*>::iterator it = clients.begin(); it < clients.end(); it++){
		ClientHandler* actual_ch = *it;
		if (ch == actual_ch){//si los ptrs son iguales
			clients.erase(it);
			cout << "El cliente salio del room" << endl;
			//Si se quedo sin clientes se pone como no activo
			if (!clients.size()) active = false;
			return true;
		}
	}
	return false;
}

bool Room::isFull(){
	return (this->clients.size() >= limit);
}

bool Room::isPlaying(){
	return currently_playing;
}

bool Room::isActive(){
	return active;
}

void Room::notifyClients(string msg){
	vector<ClientHandler*>::iterator it;
	for (it = clients.begin(); it != clients.end(); it++){
		ClientHandler* ch = *it;
		ch->sendMsg(msg);
	}
}

Room::~Room() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
