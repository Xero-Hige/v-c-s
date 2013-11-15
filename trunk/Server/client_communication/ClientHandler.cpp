/*
 * ClientHandler.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "ClientHandler.h"
#include <arpa/inet.h>
#include "../rooms/Room.h"
#include "../rooms/Lobby.h"
#include <iostream>
#include "../../libs/communication_protocol/BigEndianProtocol.h"
#include "../rooms/MatchMakingStrategy.h"
#include "ServerMsgInterpreter.h"

namespace std {

ClientHandler::ClientHandler(int s, Lobby * lob){
	this->room = NULL;
	this->keep_communicating = true;
	this->lobby = lob;
	this->sock = new FormattedSocket(s);
}
//////////////////////////////////DEBUGGGGGGGGGGGGGGGGGGGGGG
void ClientHandler::run(){
	ServerMsgInterpreter interpreter(this);
	bool exit_char_pressed = false;
	while (keep_communicating && !exit_char_pressed){
		string rcvd_msg;
		sock->recvMsg(rcvd_msg);
		exit_char_pressed = interpreter.interpret(rcvd_msg);
	}
}

void ClientHandler::exitRoom(){
	room->exitRoom(this);
	MatchMakingStrategy mm; //Lo llamo asi para q no tire otro thread
	mm.addClient(this->lobby, this);
}

void ClientHandler::sendIdsVerifMsg(){
	string msg(IDS_VERIF);
	sock->sendMsg(msg);
}

void ClientHandler::getIds(string & user, string & passwd){
	sock->recvMsg(user);
	sock->recvMsg(passwd);
}

void ClientHandler::setRoom(Room * r){
	this->room = r;
}

ClientHandler::~ClientHandler() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */