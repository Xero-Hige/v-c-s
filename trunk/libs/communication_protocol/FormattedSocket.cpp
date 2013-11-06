/*
 * FormattedSocket.cpp
 *
 *  Created on: 05/11/2013
 *      Author: juan
 */

#include "FormattedSocket.h"

namespace std {

FormattedSocket::FormattedSocket(int sockfd) : Socket(sockfd) {

}

int FormattedSocket::sendMsg(string msg){
	unsigned size = sizeof(uint32_t) + msg.length();
	char * msg_with_size = new char[size];
	darFormato(msg_with_size, msg); //BigEndianProtocol
	string s_msg(msg_with_size, size);
	int r = Socket::sendMsg(s_msg);
	delete[] msg_with_size;
	return r;
}

int FormattedSocket::recvMsg(string & msg){
	string s_size;
	Socket::recvMsg(s_size, sizeof(uint32_t));
	//Leo el size del string
	uint32_t size = readSize(s_size.c_str());
	//Recibo el mensaje de long size
	int r = Socket::recvMsg(msg, size);
	return r;
}

FormattedSocket::~FormattedSocket() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
