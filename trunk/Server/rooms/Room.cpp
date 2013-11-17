/*
 * Room.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "Room.h"
#include <iostream>

unsigned long Room::id_counter = 0;

Room::Room(Lobby * lob, unsigned limit, unsigned long r_id) {
	this->lob = lob;
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
	std::cout << "Se agrego un cliente al room " << this->id;
	std::cout << std::endl;
	clients.push_back(ch);
	ch->setRoom(this);
	return true;
}

bool Room::exitRoom(ClientHandler* ch){
	for (std::vector<ClientHandler*>::iterator it = clients.begin(); it < clients.end(); it++){
		ClientHandler* actual_ch = *it;
		if (ch == actual_ch){//si los ptrs son iguales
			clients.erase(it);
			std::cout << "El cliente salio del room" << std::endl;
			//Si se quedo sin clientes se pone como no activo
			if (!clients.size()) active = false;
			this->lob->addClient(ch);
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

void Room::notifyClients(std::string msg){
	std::vector<ClientHandler*>::iterator it;
	for (it = clients.begin(); it != clients.end(); it++){
		ClientHandler* ch = *it;
		ch->sendMsg(msg);
	}
}

Room::~Room() {
	// TODO Auto-generated destructor stub
}
