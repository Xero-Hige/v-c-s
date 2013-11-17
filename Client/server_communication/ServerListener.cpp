/*
 * ServerListener.cpp
 *
 *  Created on: 04/11/2013
 *      Author: juan
 */

#include "ServerListener.h"
#include <string>

ServerListener::ServerListener(FormattedSocket * s, ClientMsgInterpreter * c) {
	sock = s;
	msg_int = c;
	keep_listening = true;
}

void ServerListener::run(){
	while (keep_listening){
		string rcvd_msg;
		sock->recvMsg(rcvd_msg);
		if (msg_int->interpret(rcvd_msg)) keep_listening = false;
	}
}

ServerListener::~ServerListener() {
	keep_listening = false;
	sock->socketShutdown();
	this->join();
}
