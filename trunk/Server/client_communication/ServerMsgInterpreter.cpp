/*
 * MsgInterpreter.cpp
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#include "ServerMsgInterpreter.h"
#include "../../libs/messages/MsgConstants.h"
#include <iostream>

namespace std {

ServerMsgInterpreter::ServerMsgInterpreter(ClientHandler* c) {
	this->client = c;
}

void ServerMsgInterpreter::exitRoom(){
	cout << "Mensaje recibido: SALIR DEL ROOM" << endl;
	client->exitRoom();
}

void ServerMsgInterpreter::exitCharPressed(){
	//todo cortar comunicacion con el user.
}

ServerMsgInterpreter::~ServerMsgInterpreter() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */