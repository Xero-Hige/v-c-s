/*
 * ServerListener.cpp
 *
 *  Created on: 04/11/2013
 *      Author: juan
 */

#include "ServerListener.h"
#include "../backend/backend.h"
#include <string>

ServerListener::ServerListener
(Server_Connector * sc, Backend * b) : msg_int(sc, b) {
	socket = sc->getSocket();
	keep_listening = true;
}

void ServerListener::run(void * data){
	if (data) return;
	while (keep_listening){
		std::string rcvd_msg;
		socket->recvMsg(rcvd_msg);
		if (msg_int.interpret(rcvd_msg)) keep_listening = false;
	}
}

void ServerListener::stopListening(){
	keep_listening = false;
}

ServerListener::~ServerListener() {
	keep_listening = false;
//	socket->socketShutdown();
}
