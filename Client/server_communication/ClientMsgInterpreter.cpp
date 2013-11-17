/*
 * MsgInterpreter.cpp
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#include "ClientMsgInterpreter.h"
#include "../../libs/messages/MsgConstants.h"
#include <string>
#include <stdio.h>

ClientMsgInterpreter::ClientMsgInterpreter(Server_Connector* c) {
	this->client = c;
}

void ClientMsgInterpreter::exitRoom(){
	//Enviar el nuevo room, el server lo saca del room actual solo.
	client->enterRoom();
}

void ClientMsgInterpreter::interpretParticularMsg(std::string msg){
}


void ClientMsgInterpreter::exitCharPressed(){
	client->exitCharPressed();
}
ClientMsgInterpreter::~ClientMsgInterpreter() {
	// TODO Auto-generated destructor stub
}
