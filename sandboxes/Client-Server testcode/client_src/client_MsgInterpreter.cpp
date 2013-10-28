/*
 * MsgInterpreter.cpp
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#include "client_MsgInterpreter.h"
#include "../common_src/common_MsgConstants.h"
#include <string>
#include <stdio.h>

namespace std {

MsgInterpreter::MsgInterpreter(Client* c) {
	this->client = c;
}

void MsgInterpreter::exitRoom(){
	//Enviar el nuevo room
	client->enterRoom();
}

void MsgInterpreter::interpret(string s){
	if (s.compare(CLIENT_EXIT_ROOM) == 0)
		exitRoom();
}

MsgInterpreter::~MsgInterpreter() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
