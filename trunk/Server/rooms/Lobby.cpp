/*
 * Lobby.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "Lobby.h"
#include "Room.h"
#include "RoomKiller.h"
#include "MatchMakingStrategy.h"
#include "../../libs/wrappers/Thread.h"
#include "../client_communication/ClientHandler.h"
#include <iostream>

Lobby::Lobby(){
	//room_killer.setRooms(&rooms);//No se pq no me deja inicializarlo de entrada...
	//room_killer.start();
}

//Utilizo pthreads sin usar la clase Thread que construimos
//porque necesito pasar parametros a lo que seria el metodo run().
//thread_data contiene los params que necesito
struct thread_data {
	Lobby * lobby;
	ClientHandler * ch;
};

void * threadAddClient(void * data){
	struct thread_data * t_data = (struct thread_data *)data;
	MatchMakingStrategy mms;
	mms.addClient(t_data->lobby, t_data->ch);
	t_data->ch->start();
	return NULL;
}

void Lobby::addNewClient(ClientHandler * ch) {
	pthread_t thread;
	struct thread_data data;
	data.lobby = this;
	data.ch = ch;
	pthread_create(&thread, NULL, threadAddClient, (void *) &data);
}

void Lobby::addRoom(unsigned long id, Room * r){
	rooms.insert(map_pair(id,r));
}

void Lobby::addClient(ClientHandler * ch){
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
//	room_killer.stop();
}
