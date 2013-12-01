/*
 * Socket.cpp
 *
 *  Created on: 03/11/2013
 *      Author: juan
 */

#include "Socket.h"
#include <sys/socket.h>
#include <string>
#include <iostream>

Socket::Socket(int sockfd) {
	// TODO Auto-generated constructor stub
	this->socket = sockfd;
}

int Socket::sendMsg(std::string msg){
	int r = socketSend(msg.c_str(), msg.length());
	return r;
}

int Socket::socketSend(const char * buf, size_t length){
	unsigned bytes_enviados = 0;
	while (bytes_enviados == 0){
		bytes_enviados = send(socket, buf, length, 0);
	}
	return bytes_enviados;
}

int Socket::recvMsg(std::string & msg, size_t length){
	char * c_msg = new char[length]();
	int r = socketRecv(c_msg, length);
	msg.clear();
	msg.append(c_msg, length);
	delete[] c_msg;
	return r;
}

int Socket::getSocket(){
	return socket;
}

void Socket::socketShutdown(){
	shutdown(socket, 0);
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
