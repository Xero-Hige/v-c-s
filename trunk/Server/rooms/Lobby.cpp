/*
 * Lobby.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "Lobby.h"
#include "Room.h"
#include "MatchMakingStrategy.h"
#include "../../libs/wrappers/Thread.h"
#include <iostream>

Lobby::Lobby(){
	room_killer.setRooms(&rooms);//No se pq no me deja inicializarlo de entrada...
	room_killer.start();
}

//Utilizo pthreads sin usar la clase Thread que construimos porque necesito pasar
//parametros a lo que seria el metodo run().
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

void Lobby::addClient(ClientHandler * ch){
	MatchMakingStrategy mms;
	mms.addClient(this, ch);
}

Lobby::~Lobby() {
	room_killer.stop();
}
