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
	char verif[] = IDS_VERIF;
	this->socketSend(verif, IDS_VERIF_SIZE);
}

void ClientHandler::getIds(void * buf, size_t size){
	this->socketReceive(buf, size);
}

void ClientHandler::getAuthType(void * buf, size_t length){
	this->socketReceive(buf, length);
}

int ClientHandler::socketReceive(void * buf, size_t length){
	return recv(this->sock, buf, length, 0);
}

ClientHandler::~ClientHandler() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
