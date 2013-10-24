/*
 * ServerHandler.cpp
 *
 *  Created on: 24/10/2013
 *      Author: juan
 */

#include "client_ServerHandler.h"
#include <unistd.h> //close
#include <arpa/inet.h> //inet_addr, htons, server_addr
#include "../common_src/common_BigEndianProtocol.h"

namespace std {

ServerHandler::ServerHandler(int sockfd) {
	this->socket = sockfd;
}

int& ServerHandler::getSocket(){
	return socket;
}

int ServerHandler::clientSend(char * buf, size_t length){
	unsigned bytes_enviados = 0;
	while (bytes_enviados == 0){
		bytes_enviados = send(socket, buf, length, 0);
	}
	return bytes_enviados;
}

int ServerHandler::sendMsg(string msg){
	unsigned size = sizeof(uint32_t) + msg.length();
	char * msg_with_size = new char[size];
	darFormato(msg_with_size, msg);
	int r = clientSend(msg_with_size, size);
	delete[] msg_with_size;
	return r;
}

int ServerHandler::recvMsg(string & msg){
	char c_size[sizeof(uint32_t)];
	clientReceive(c_size, sizeof(uint32_t));
	uint32_t size = readSize(c_size);
	char * c_msg = new char[size];
	int r = clientReceive(c_msg, size);
	msg.append(c_msg, size);
	delete[] c_msg;
	return r;
}

int ServerHandler::clientReceive(char * buf, size_t length){
	return recv(socket, buf, length, 0);
}

void ServerHandler::closeConnection(){
	close(socket);
}
ServerHandler::~ServerHandler() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
