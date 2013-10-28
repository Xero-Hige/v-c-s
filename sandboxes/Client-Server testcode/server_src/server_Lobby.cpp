/*
 * Lobby.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "server_Lobby.h"
#include "server_Room.h"
#include "server_MatchMakingStrategy.h"
#include "../common_src/common_Thread.h"
#include <iostream>

namespace std {

Lobby::Lobby() {
	// TODO Auto-generated constructor stub

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
	return NULL;
}

void Lobby::addClient(ClientHandler * ch) {
	pthread_t thread;
	struct thread_data data;
	data.lobby = this;
	data.ch = ch;
	pthread_create(&thread, NULL, threadAddClient, (void *) &data);
}

Lobby::~Lobby() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
