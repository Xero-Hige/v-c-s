/*
 * MsgInterpreter.cpp
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#include "ServerMsgInterpreter.h"
#include "../../libs/messages/MsgConstants.h"
#include <iostream>

ServerMsgInterpreter::ServerMsgInterpreter(ClientHandler* c) {
	this->client = c;
}

void ServerMsgInterpreter::exitRoom(){
	std::cout << "Mensaje recibido: SALIR DEL ROOM" << std::endl;
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
