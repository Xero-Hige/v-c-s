/*
 * Socket.cpp
 *
 *  Created on: 03/11/2013
 *      Author: juan
 */

#include "Socket.h"

namespace std {

Socket::Socket(int sockfd) {
	// TODO Auto-generated constructor stub
	this->socket = sockfd;
}

int Socket::sendMsg(string msg){
	unsigned size = sizeof(uint32_t) + msg.length();
	char * msg_with_size = new char[size];
	darFormato(msg_with_size, msg);
	int r = socketSend(msg_with_size, size);
	delete[] msg_with_size;
	return r;
}

int Socket::socketSend(char * buf, size_t length){
	unsigned bytes_enviados = 0;
	while (bytes_enviados == 0){
		bytes_enviados = send(socket, buf, length, 0);
	}
	return bytes_enviados;
}

int Socket::recvMsg(string & msg){
	char c_size[sizeof(uint32_t)];
	socketRecv(c_size, sizeof(uint32_t));
	uint32_t size = readSize(c_size);
	char * c_msg = new char[size];
	int r = socketRecv(c_msg, size);
	msg.append(c_msg, size);
	delete[] c_msg;
	return r;
}

int Socket::getSocket(){
	return socket;
}

void Socket::closeConnection(){
	close(socket);
}

int Socket::socketRecv(char * buf, size_t length){
	return recv(socket, buf, length, 0);
}

Socket::~Socket() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
