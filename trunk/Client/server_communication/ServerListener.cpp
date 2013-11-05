/*
 * ServerListener.cpp
 *
 *  Created on: 04/11/2013
 *      Author: juan
 */

#include "ServerListener.h"
#include <string>

namespace std {

ServerListener::ServerListener(Socket * s, ClientMsgInterpreter * c) {
	sock = s;
	msg_int = c;
	keep_listening = true;
}

void ServerListener::run(){
	while (keep_listening){
		string rcvd_msg;
		sock->recvMsg(rcvd_msg);
		msg_int->interpret(rcvd_msg);
	}
}

void ServerListener::notifyCommunicationStart(){
	keep_listening = false;
	//todo
	//shutdown socket
	this->join();
}

void ServerListener::notifyCommunicationEnd(){
	keep_listening = true;
	this->start();
}

ServerListener::~ServerListener() {
}

} /* namespace std */
