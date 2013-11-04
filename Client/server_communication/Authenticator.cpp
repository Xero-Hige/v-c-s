/*
 * Authenticator.cpp
 *
 *  Created on: 21/10/2013
 *      Author: juan
 */

#include "Authenticator.h"
#include "../../libs/messages/MsgConstants.h"
#include "../../libs/communication_protocol/BigEndianProtocol.h"
#include <cstring>

namespace std {

Authenticator::Authenticator(Server_Connector * c) {
	this->client = c;
}

bool Authenticator::receiveAuthVerif(){
	string s(IDS_VERIF);
	return verificateMessage(s);
}

bool Authenticator::verificateMessage(string msg){
	//Compara si el mensaje que envio el server coincide con 'msg'
	string recvd_msg;
	client->sock->recvMsg(recvd_msg);
	if (recvd_msg.compare(msg) == 0) {
		return true;
	}
	return false;
}

bool Authenticator::sendIds
(string & user, string & passwd, string & auth_type){
	this->client->sock->sendMsg(auth_type);
	this->client->sock->sendMsg(user);
	this->client->sock->sendMsg(passwd);
	if (this->receiveAuthVerif()) return true;
	return false;
}

Authenticator::~Authenticator() {
}

} /* namespace std */
