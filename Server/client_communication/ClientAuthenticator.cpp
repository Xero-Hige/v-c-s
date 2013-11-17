/*
 * ClientAuthenticator.cpp
 *
 *  Created on: 23/10/2013
 *      Author: juan
 */

#include "ClientAuthenticator.h"
#include "../../libs/messages/MsgConstants.h"
#include <cstring>


ClientAuthenticator::ClientAuthenticator(int socket) : sock(socket) {
}

bool ClientAuthenticator::authenticate(){
	//Determina si el cliente quiere registrarse o logearse
	std::string s_auth_type;
	sock.recvMsg(s_auth_type);
	int auth_type = atoi (s_auth_type.c_str());
	if (auth_type == TYPE_LOGIN)
		return login();
	else /*if (auth_type == TYPE_REGISTER)*/
		return registrate();
}

void ClientAuthenticator::sendIdsVerifMsg(){
	std::string msg(IDS_VERIF);
	sock.sendMsg(msg);
}

void ClientAuthenticator::getIds(std::string & user, std::string & passwd){
	sock.recvMsg(user);
	sock.recvMsg(passwd);
}


bool ClientAuthenticator::registrate(){
	//todo
	std::string user, passwd;
	this->getIds(user, passwd);
	//DO SHIT
	this->sendIdsVerifMsg();
	return true;
}

bool ClientAuthenticator::login(){
	std::string user, passwd;
	this->getIds(user, passwd);
	//todo REALIZAR CHEQUEO DE IDS
	//if (chequeoIds(ids))
	this->sendIdsVerifMsg();
	return true;
	//else
	//return false;
}


ClientAuthenticator::~ClientAuthenticator() {
	// TODO Auto-generated destructor stub
}

