/*
 * ClientHandler.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "server_ClientHandler.h"
#include <arpa/inet.h>
#include <iostream>
#include "../common_src/common_MsgConstants.h"
#include "../common_src/common_BigEndianProtocol.h"

namespace std {

ClientHandler::ClientHandler(int sock) {
	this->sock = sock;
	this->keep_communicating = true;
}
//////////////////////////////////DEBUGGGGGGGGGGGGGGGGGGGGGG
void ClientHandler::run(){
	while (keep_communicating){
		string rcvd_msg;
		recvMsg(rcvd_msg);
		if (rcvd_msg.compare("q") == 0) {
			cout << "Mensaje recibido: SALIDA" << endl;
			string msg2("EXIT");
			sendMsg(msg2);
			break;
		}
		cout << "Mensaje recibido: ";
		cout << rcvd_msg << endl;
		string msg2("CONFIRMACION");
		sendMsg(msg2);
	}
	keep_communicating = false;
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
	getUser(user);
	getPasswd(passwd);
}

void ClientHandler::getUser(string & user){
	recvMsg(user);
}

void ClientHandler::getPasswd(string & passwd){
	recvMsg(passwd);
}

void ClientHandler::getAuthType(string & auth_type){
	recvMsg(auth_type);
}

int ClientHandler::socketReceive(void * buf, size_t length){
	return recv(this->sock, buf, length, 0);
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
