/*
 * Lobby.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "Lobby.h"
#include "Room.h"
#include "MatchMakingStrategy.h"
#include "../../libs/database/MyDatabase.h"
#include "../client_communication/ClientHandler.h"
#include <iostream>
#include <map>

Lobby::Lobby(MyDatabase * data){
	db = data;
}

//Utilizo pthreads sin usar la clase Thread que construimos
//porque necesito pasar parametros a lo que seria el metodo run().
//thread_data contiene los params que necesito
struct thread_data {
	Lobby * lobby;
	ClientHandler * ch;
};

void Lobby::run(void * data){
	struct thread_data * t_data = (struct thread_data *)data;
	MatchMakingStrategy mms;
	mms.addClient(t_data->lobby, t_data->ch);
	t_data->ch->start();
	delete t_data;
}

void Lobby::addNewClient(ClientHandler * ch) {
	struct thread_data * data = new struct thread_data();
	data->lobby = this;
	data->ch = ch;
	this->start((void*)data);
}

void Lobby::addRoom(unsigned long id, Room * r){
	rooms.insert(map_pair(id,r));
}

void Lobby::addClient(ClientHandler * ch){
	db->updateLevel(ch->getUserid(), ch->getLevel());
	MatchMakingStrategy mms;
	mms.addClient(this, ch);
}

Room * Lobby::getRoom(unsigned long id){
	std::map<unsigned long, Room*>::iterator it;
	it = rooms.find(id); //intenta encontrar la key
	if (it == rooms.end()){//Si no la encontro no existe un room con ese id...
		return NULL;
	}else{
		return it->second;
	}
}

void Lobby::endMatch(unsigned long id){
	if (rooms.size() == 0) return;
	std::map<unsigned long, Room*>::iterator it;
	it = rooms.find(id);
	if (it == rooms.end()){
		return;//Si no lo encontro termina
	} else {
		Room * room_actual = it->second;
		delete room_actual;
	}
}

//void Lobby::endAllMatches(){
//	std::map<unsigned long, Room*>::iterator it = rooms.begin();
//	while(it != rooms.end()){
//		Room* actual_room = it->second;
//		delete actual_room;
//		//erase(it++) funciona porque borra y luego incrementa el iter
//		rooms.erase(it++);//MAGIA
//	}
//}

Room * Lobby::getNotFullNotPlayingRoom(){
	if (rooms.size() == 0) return 0;
	std::map<unsigned long, Room*>::iterator it;
	for (it = rooms.begin(); it != rooms.end(); it++){
		if (! it->second->isFull() && ! it->second->isPlaying())
			return it->second;
	}
	return 0;
}

Lobby::~Lobby() {
//	endAllMatches();
	std::map<unsigned long, Room*>::iterator it = rooms.begin();
	while(it != rooms.end()){
		Room* actual_room = it->second;
		delete actual_room;
		//erase(it++) funciona porque borra y luego incrementa el iter
		rooms.erase(it++);//MAGIA
	}
}
