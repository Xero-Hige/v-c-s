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

Authenticator::Authenticator() {
	this->sock = NULL;
}

bool Authenticator::receiveAuthVerif(){
	std::string s(IDS_VERIF);
	return verificateMessage(s);
}

void Authenticator::setSocket(FormattedSocket * s){
	this->sock = s;
}

bool Authenticator::verificateMessage(std::string msg){
	//Compara si el mensaje que envio el server coincide con 'msg'
	std::string recvd_msg;
	sock->recvMsg(recvd_msg);
	if (recvd_msg.compare(msg) == 0) {
		return true;
	}
	return false;
}

bool Authenticator::authenticate
(std::string user, std::string passwd, std::string auth_type){
	sock->sendMsg(auth_type);
	sock->sendMsg(user);
	sock->sendMsg(passwd);
	if (this->receiveAuthVerif())
		//se autentico
		return true;
	else
		return false;
}

Authenticator::~Authenticator() {
}
