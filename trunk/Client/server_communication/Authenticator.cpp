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
#include <string>

Authenticator::Authenticator() {
	this->sock = NULL;
}

bool Authenticator::receiveAuthVerif(){
	std::string verif_msg(IDS_VERIF);
	std::string server_msg;
	sock->recvMsg(server_msg);
	return (server_msg.compare(verif_msg) == 0);
}

void Authenticator::setSocket(FormattedSocket * s){
	this->sock = s;
}

bool Authenticator::authenticate
(std::string user, std::string passwd, std::string auth_type){
	sock->sendMsg(auth_type);
	sock->sendMsg(user);
	sock->sendMsg(passwd);
	return (this->receiveAuthVerif());
}

Authenticator::~Authenticator() {
}
