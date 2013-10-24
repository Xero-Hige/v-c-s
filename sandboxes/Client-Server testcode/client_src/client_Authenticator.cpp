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
	string recvd_msg;
	client->s_handler->recvMsg(recvd_msg);
	if (recvd_msg.compare(msg) == 0) {
		return true;
	}
	return false;
}

void Authenticator::sendAuth(string & user, string & passwd){
	sendUser(user);
	sendPasswd(passwd);
}

void Authenticator::sendUser(string & user){
	this->client->s_handler->sendMsg(user);
}

void Authenticator::sendPasswd(string & passwd){
	this->client->s_handler->sendMsg(passwd);
}

void Authenticator::sendAuthType(string & auth_type){
	this->client->s_handler->sendMsg(auth_type);
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
