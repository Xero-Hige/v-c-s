/*
 * FormattedSocket.cpp
 *
 *  Created on: 05/11/2013
 *      Author: juan
 */

#include "FormattedSocket.h"
#include "HMAC.h"
#include <string>
#include <iostream>

FormattedSocket::FormattedSocket(int sockfd) : Socket(sockfd) {
}

int FormattedSocket::sendMsg(std::string msg){
	unsigned size = sizeof(uint32_t) + msg.length();
	char * msg_with_size = new char[size];
	darFormato(msg_with_size, msg); //BigEndianProtocol
	std::string s_msg(msg_with_size, size);
	int r = Socket::sendMsg(s_msg);
	delete[] msg_with_size;
	return r;
}

int FormattedSocket::sendSignedMsg(std::string msg, std::string key){
	HMACSignedMsg(msg, key);
	return sendMsg(msg);
}

bool FormattedSocket::recvSignedMsg
(std::string & msg, std::string key, int & recvd_bytes){
	std::string signed_msg;
	recvd_bytes = recvMsg(signed_msg);
	if (checkSignedMsg(signed_msg, key)){
		msg.clear();
		msg.append(signed_msg.substr(0, signed_msg.size() - SHA_DIGEST_SIZE));
		return true;
	}
	return false;
}

int FormattedSocket::recvMsg(std::string & msg){
	std::string s_size;
	Socket::recvMsg(s_size, sizeof(uint32_t));
	//Leo el size del string
	uint32_t size = readSize(s_size.c_str());
	//Recibo el mensaje de long size
	int r = Socket::recvMsg(msg, size);
	return r;
}

FormattedSocket::~FormattedSocket() {
	std::cout << "CIERRE DE CONEXION" << std::endl;
	socketShutdown();
	closeConnection();
}
