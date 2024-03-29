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
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::string;

#define FILE_COMMON_NAME "level"
#define FILE_EXT ".json"

unsigned long Room::id_counter = 0;

Room::Room(Lobby * lob, unsigned limit,unsigned lvl, unsigned long r_id):
	game_manager(this, &level_reader){
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
	active = true;
	//TODO leer las cosas del archivo y mandarlo acá
	string level_data = loadLevel();
	level_reader.changeLevelData(level_data);
//	this->limit = level_reader.getNumberOfPlayers();
	game_manager.configure();
}

std::string Room::getLevelName(){
	std::stringstream name;
	name << FILE_COMMON_NAME << this->level << FILE_EXT;
	return name.str();
}

std::string Room::loadLevel(){
	std::string path = getLevelName();
	std::ifstream file(path.c_str());
	std::string str((std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>());
	return str;
}


bool Room::addClient(ClientHandler* ch){
	if (this->clients.size() >= limit ||
			currently_playing ||
			ch->getLevel() < this->level) return false;
	std::cout << "Se agrego un cliente al room " << this->id;
	std::cout << std::endl;
	clients.push_back(ch);
	string user_id = ch->getUserid();
	usernames.push_back(user_id);
	ch->setRoom(this);
	game_manager.addPlayer(user_id);
	return true;
}

void Room::eraseUsername(std::string username){
	for (std::vector<std::string>::iterator it = usernames.begin();
			it != usernames.end();
			it++){
		std::string username_actual = *it;
		if (username_actual.compare(username) == 0){
			usernames.erase(it);
			game_manager.removePlayer(username);
			return;
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
			ch->setRoom(NULL);
			eraseUsername(ch->getUserid());
			//Si sigue activo lo agrega a un room.
			if(ch->isActive()) this->lob->addClient(ch);
			else delete ch;
			std::cout << "El cliente salio del room" << std::endl;
			updateActive();
			return true;
		}
	}
	updateActive();
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

void Room::updateActive(){
	active = clients.size() > 0;
}

void Room::endMatch(){
	for (std::vector<ClientHandler*>::iterator it = clients.begin();
			it < clients.end();
			it++){
		exitRoom(*it);
	}
	updateActive();
}

void Room::notifyClients(std::string msg){
	std::vector<ClientHandler*>::iterator it;
	for (it = clients.begin(); it != clients.end(); it++){
		ClientHandler* ch = *it;
		ch->sendMsg(msg);
	}
}

void Room::swapMade(std::string user_id, Position position1, Position position2) {
    game_manager.makeSwap(position1, position2, user_id);
}

void Room::getSerializedBoardProducts(std::string& serialized_products) {
    game_manager.getSerializedBoardProducts(serialized_products);
}

void Room::getSerializedReplacementProducts(std::string& serialized_products) {
    game_manager.getSerializedReplacementProducts(serialized_products);
}

Room::~Room() {
	if (clients.size() <= 0) return;
	for (std::vector<ClientHandler*>::iterator it = clients.begin();
			it < clients.end();
			it++){
		ClientHandler* actual_ch = *it;
		actual_ch->closeConnection();
		//actual_ch->join();
		delete actual_ch;
	}
}
