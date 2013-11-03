/*
 * MsgInterpreter.cpp
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#include "server_ServerMsgInterpreter.h"
#include "../common_src/common_MsgConstants.h"
#include <iostream>

namespace std {

ServerMsgInterpreter::ServerMsgInterpreter(ClientHandler* c) {
	this->client = c;
}

void ServerMsgInterpreter::exitRoom(){
	cout << "Mensaje recibido: SALIR DEL ROOM" << endl;
	client->exitRoom();
}

ServerMsgInterpreter::~ServerMsgInterpreter() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
