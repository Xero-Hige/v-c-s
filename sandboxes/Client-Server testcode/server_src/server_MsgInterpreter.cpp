/*
 * MsgInterpreter.cpp
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#include "server_MsgInterpreter.h"
#include "../common_src/common_MsgConstants.h"
#include <iostream>

namespace std {

MsgInterpreter::MsgInterpreter(ClientHandler* c) {
	this->client = c;
}

void MsgInterpreter::exitRoom(){
	cout << "Mensaje recibido: SALIR DEL ROOM" << endl;
	client->exitRoom();
}

void MsgInterpreter::interpret(string s) {
	cout << s << endl;
	if (s.compare(CLIENT_EXIT_ROOM) == 0)
		exitRoom();
}

MsgInterpreter::~MsgInterpreter() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
