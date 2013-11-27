/*
 * ServerListener.cpp
 *
 *  Created on: 04/11/2013
 *      Author: juan
 */

#include "ServerListener.h"
#include <string>

ServerListener::ServerListener(Server_Connector * sc) : msg_int(sc) {
	socket = sc->getSocket();
	keep_listening = true;
}

void ServerListener::run(){
	while (keep_listening){
		std::string rcvd_msg;
		socket->recvMsg(rcvd_msg);
		if (msg_int.interpret(rcvd_msg)) keep_listening = false;
	}
}

ServerListener::~ServerListener() {
	keep_listening = false;
	socket->socketShutdown();
	this->join();
}
