/*
 * Room.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "Room.h"
#include "../client_communication/ClientHandler.h"
#include "Lobby.h"
#include <iostream>
#include <vector>
#include <string>

unsigned long Room::id_counter = 0;

Room::Room(Lobby * lob, unsigned limit,unsigned lvl, unsigned long r_id) {
	this->lob = lob;
	if (!r_id){
		//el id se auto-genera
		this->id = Room::id_counter;
		Room::id_counter++;
	} else {
		this->id = r_id;
	}
	this->level = lvl;
	this->limit = limit;
	currently_playing = false;
}

bool Room::addClient(ClientHandler* ch){
	if (this->clients.size() >= limit ||
			currently_playing ||
			ch->getLevel() < this->level) return false;
	std::cout << "Se agrego un cliente al room " << this->id;
	std::cout << std::endl;
	clients.push_back(ch);
	usernames.push_back(ch->getUserid());
	ch->setRoom(this);
	return true;
}

void Room::eraseUsername(std::string username){
	for (std::vector<std::string>::iterator it = usernames.begin();
			it != usernames.end();
			it++){
		std::string username_actual = *it;
		if (username_actual.compare(username) == 0){
			usernames.erase(it);
		}
	}
}

bool Room::exitRoom(ClientHandler* ch){
	for (std::vector<ClientHandler*>::iterator it = clients.begin();
			it != clients.end();
			it++){
		ClientHandler* actual_ch = *it;
		if (ch == actual_ch){//si los ptrs son iguales
			clients.erase(it);
			std::cout << "El cliente salio del room" << std::endl;
			//Si se quedo sin clientes se termine la partida
			if (!clients.size()) this->endMatch();
			ch->setRoom(NULL);
			eraseUsername(ch->getUserid());
			//Si sigue activo lo agrega a un room.
			if(ch->isActive()) this->lob->addClient(ch);
			else delete ch;
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

void Room::endMatch(){
	for (std::vector<ClientHandler*>::iterator it = clients.begin();
			it < clients.end();
			it++){
		exitRoom(*it);
	}
	this->lob->endMatch(this->id);
}

void Room::notifyClients(std::string msg){
	std::vector<ClientHandler*>::iterator it;
	for (it = clients.begin(); it != clients.end(); it++){
		ClientHandler* ch = *it;
		ch->sendMsg(msg);
	}
}

Room::~Room() {
	for (std::vector<ClientHandler*>::iterator it = clients.begin();
			it < clients.end();
			it++){
		ClientHandler* actual_ch = *it;
		actual_ch->closeConnection();
		actual_ch->join();
		delete actual_ch;
	}
}
