/*
 * ClientHandler.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "ClientHandler.h"
#include <arpa/inet.h>
#include "../rooms/Room.h"
#include <iostream>
#include "../../libs/communication_protocol/BigEndianProtocol.h"
#include "../rooms/MatchMakingStrategy.h"
#include "ServerMsgInterpreter.h"
#include <string>

ClientHandler::ClientHandler(int s){
	this->keep_listening = true;
	this->sock = new FormattedSocket(s);
	this->room = NULL;
}

void ClientHandler::run(){
	while (keep_listening){
		std::string rcvd_msg;
		sock->recvMsg(rcvd_msg);
		ServerMsgInterpreter msg_int(this);
		if (msg_int.interpret(rcvd_msg)) keep_listening = false;
	}
}

void ClientHandler::exitRoom(){
	room->exitRoom(this);
}

void ClientHandler::setPassword(std::string pass){
	this->passwd = pass;
}

void ClientHandler::setRoom(Room * r){
	this->room = r;
}

void ClientHandler::recvMsg(std::string & s){
	int recvd_bytes;
	if (!this->sock->recvSignedMsg(s, this->passwd, recvd_bytes))
		sock->closeConnection();
}

void ClientHandler::sendMsg(std::string s){
	this->sock->sendMsg(s);
}

ClientHandler::~ClientHandler() {
	// TODO Auto-generated destructor stub
}
