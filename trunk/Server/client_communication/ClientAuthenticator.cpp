/*
 * ClientAuthenticator.cpp
 *
 *  Created on: 23/10/2013
 *      Author: juan
 */

#include "ClientAuthenticator.h"
#include "../../libs/messages/MsgConstants.h"
#include <cstring>

namespace std {

ClientAuthenticator::ClientAuthenticator(ClientHandler * ch) {
	this->client = ch;
}

bool ClientAuthenticator::authenticate(){
	//Determina si el cliente quiere registrarse o logearse
	string s_auth_type;
	this->client->recvMsg(s_auth_type);
	int auth_type = atoi (s_auth_type.c_str());
	if (auth_type == TYPE_LOGIN)
		return login();
	else /*if (auth_type == TYPE_REGISTER)*/
		return registrate();
}

bool ClientAuthenticator::registrate(){
	//todo
	string user, passwd;
	client->getIds(user, passwd);
	//DO SHIT
	client->sendIdsVerifMsg();
	return true;
}

bool ClientAuthenticator::login(){
	string user, passwd;
	client->getIds(user, passwd);
	//todo REALIZAR CHEQUEO DE IDS
	//if (chequeoIds(ids))
	client->sendIdsVerifMsg();
	return true;
	//else
	//return false;
}


ClientAuthenticator::~ClientAuthenticator() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
