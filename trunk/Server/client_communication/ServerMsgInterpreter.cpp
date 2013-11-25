/*
 * MsgInterpreter.cpp
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#include "ServerMsgInterpreter.h"
#include "../../libs/messages/MsgConstants.h"
#include <string>

ServerMsgInterpreter::ServerMsgInterpreter(ClientHandler* c) {
	this->client = c;
}

void ServerMsgInterpreter::exitRoom(){
	client->exitRoom();
}

void ServerMsgInterpreter::exitCharPressed(){
	//todo cortar comunicacion con el user.
}

void ServerMsgInterpreter::interpretParticularMsg(std::string msg){
}

ServerMsgInterpreter::~ServerMsgInterpreter() {
	// TODO Auto-generated destructor stub
}
