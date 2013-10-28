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
#include "server_MsgInterpreter.h"
#include <iostream>
#include "../common_src/common_MsgConstants.h"
#include "../common_src/common_BigEndianProtocol.h"

namespace std {

ClientHandler::ClientHandler(int sock, Lobby * lob) {
	this->room = NULL;
	this->sock = sock;
	this->keep_communicating = true;
	this->lobby = lob;
}
//////////////////////////////////DEBUGGGGGGGGGGGGGGGGGGGGGG
void ClientHandler::run(){
	MsgInterpreter interpreter(this);
	while (keep_communicating){
		string rcvd_msg;
		recvMsg(rcvd_msg);
		if (rcvd_msg.compare("q") == 0) {
			cout << "Mensaje recibido: SALIDA" << endl;
			break;
		}
		interpreter.interpret(rcvd_msg);
	}
}

void ClientHandler::exitRoom(){
	room->exitRoom(this);
//	lobby->addClient(this);
}

int ClientHandler::socketSend(const void * buf, size_t length){
	unsigned bytes_enviados = 0;
	//Solo si no se envio nada reenvia. Esto es para evitar que se cuelgue
	//(el cliente) cuando el send del server ocurre antes que el receive
	//del cliente
	while (bytes_enviados == 0){
		bytes_enviados = send(this->sock, buf, length, 0);
	}
	return bytes_enviados;
}

void ClientHandler::sendIdsVerifMsg(){
	string msg(IDS_VERIF);
	sendMsg(msg);
}

void ClientHandler::getIds(string & user, string & passwd){
	recvMsg(user);
	recvMsg(passwd);
}

int ClientHandler::socketReceive(void * buf, size_t length){
	return recv(this->sock, buf, length, 0);
}

void ClientHandler::setRoom(Room * r){
	this->room = r;
}

int ClientHandler::sendMsg(string msg){
	unsigned size = sizeof(uint32_t) + msg.length();
	char * msg_with_size = new char[size];
	darFormato(msg_with_size, msg);
	int r = socketSend(msg_with_size, size);
	delete[] msg_with_size;
	return r;
}

int ClientHandler::recvMsg(string & msg){
	char c_size[sizeof(uint32_t)];
	socketReceive(c_size, sizeof(uint32_t));
	uint32_t size = readSize(c_size);
	char * c_msg = new char[size];
	int r = socketReceive(c_msg, size);
	msg.append(c_msg, size);
	delete[] c_msg;
	return r;
}

ClientHandler::~ClientHandler() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
