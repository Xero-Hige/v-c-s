/*
 * Authenticator.cpp
 *
 *  Created on: 21/10/2013
 *      Author: juan
 */

#include "client_Authenticator.h"
#include "../common_src/common_MsgConstants.h"
#include "../common_src/common_BigEndianProtocol.h"
#include <cstring>

namespace std {

Authenticator::Authenticator(Client * c) {
	this->client = c;
}

bool Authenticator::receiveAuthVerif(){
	string s(IDS_VERIF);
	return verificateMessage(s);
}

bool Authenticator::verificateMessage(string msg){
	//Compara si el mensaje que envio el server coincide con 'msg'
	char c_size[sizeof(uint32_t)];
	client->clientReceive(c_size, sizeof(uint32_t));
	uint32_t size = readSize(c_size);
	string recvd_msg;
	char * c_msg = new char[size];
	client->clientReceive(c_msg, size);
	recvd_msg.append(c_msg, size);
	if ( recvd_msg.compare(msg) == 0) {
		delete[] c_msg;
		return true;
	}
	delete[] c_msg;
	return false;
}

void Authenticator::sendAuth(string & user, string & passwd){
	sendUser(user);
	sendPasswd(passwd);
}

void Authenticator::sendUser(string & user){
	unsigned size = sizeof(uint32_t) + user.length();
	char * msg_with_size = new char[size];
	darFormato(msg_with_size, user);
	this->client->clientSend(msg_with_size, size);
	delete[] msg_with_size;
}

void Authenticator::sendPasswd(string & passwd){
	unsigned size = sizeof(uint32_t) + passwd.length();
	char * msg_with_size = new char[size];
	darFormato(msg_with_size, passwd);
	this->client->clientSend(msg_with_size, size);
	delete[] msg_with_size;
}

void Authenticator::sendAuthType(string & auth_type){
	unsigned size = sizeof(uint32_t) + auth_type.length();
	char * msg_with_size = new char[size];
	darFormato(msg_with_size, auth_type);
	this->client->clientSend(msg_with_size, size);
	delete[] msg_with_size;
}

bool Authenticator::sendIds
(string & user, string & passwd, string & auth_type){
	this->sendAuthType(auth_type);
	this->sendAuth(user, passwd);
	if (this->receiveAuthVerif()) return true;
	return false;
}

Authenticator::~Authenticator() {
}

} /* namespace std */
