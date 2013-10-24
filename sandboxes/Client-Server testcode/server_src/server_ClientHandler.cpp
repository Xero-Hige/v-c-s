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
		char msg[80];
		socketReceive(msg, 80);
		if (msg[0] == 'q') {
			cout << "Mensaje recibido: SALIDA" << endl;
			char msg2[] = "EXIT";
			socketSend(msg2, 80);
			break;
		}
		cout << "Mensaje recibido: ";
		cout << msg << endl;
		char msg2[] = "CONFIRMACION";
		socketSend(msg2, 80);
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
	char * msg_with_size = new char[sizeof(uint32_t) + msg.length()];
	darFormato(msg_with_size, msg);
	this->socketSend(msg_with_size, sizeof(uint32_t) + msg.length());
	delete[] msg_with_size;
}

void ClientHandler::getIds(string & user, string & passwd){
	getUser(user);
	getPasswd(passwd);
}

void ClientHandler::getUser(string & user){
	char c_size[sizeof(uint32_t)];
	this->socketReceive(c_size, sizeof(uint32_t));
	uint32_t size = readSize(c_size);
	char * c_user = new char[size];
	this->socketReceive(c_user, size);
	user.append(c_user, size);
	delete[] c_user;
}

void ClientHandler::getPasswd(string & passwd){
	char c_size[sizeof(uint32_t)];
	this->socketReceive(c_size, sizeof(uint32_t));
	uint32_t size = readSize(c_size);
	char * c_passwd = new char[size];
	this->socketReceive(c_passwd, size);
	passwd.append(c_passwd, size);
	delete[] c_passwd;
}

void ClientHandler::getAuthType(string & auth_type){
	char c_size[sizeof(uint32_t)];
	this->socketReceive(c_size, sizeof(uint32_t));
	uint32_t size = readSize(c_size);
	auth_type.clear();
	char * c_auth_type = new char[size];
	this->socketReceive(c_auth_type, size);
	auth_type.append(c_auth_type, size);
	delete[] c_auth_type;
}

int ClientHandler::socketReceive(void * buf, size_t length){
	return recv(this->sock, buf, length, 0);
}

ClientHandler::~ClientHandler() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
