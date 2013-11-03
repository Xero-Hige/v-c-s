/*
 * ClientHandler.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "server_ClientHandler.h"
#include <arpa/inet.h>
#include "server_Room.h"
#include "server_Lobby.h"
#include <iostream>
#include "../common_src/common_MsgConstants.h"
#include "../common_src/common_BigEndianProtocol.h"
#include "server_MatchMakingStrategy.h"
#include "server_ServerMsgInterpreter.h"

namespace std {

ClientHandler::ClientHandler(int s, Lobby * lob) : Socket(s) {
	this->room = NULL;
	this->keep_communicating = true;
	this->lobby = lob;
}
//////////////////////////////////DEBUGGGGGGGGGGGGGGGGGGGGGG
void ClientHandler::run(){
	ServerMsgInterpreter interpreter(this);
	bool exit_char_pressed = false;
	while (keep_communicating && !exit_char_pressed){
		string rcvd_msg;
		recvMsg(rcvd_msg);
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
	sendMsg(msg);
}

void ClientHandler::getIds(string & user, string & passwd){
	recvMsg(user);
	recvMsg(passwd);
}

void ClientHandler::setRoom(Room * r){
	this->room = r;
}

ClientHandler::~ClientHandler() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
