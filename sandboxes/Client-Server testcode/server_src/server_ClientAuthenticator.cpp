/*
 * ClientAuthenticator.cpp
 *
 *  Created on: 23/10/2013
 *      Author: juan
 */

#include "server_ClientAuthenticator.h"
#include "../common_src/common_MsgConstants.h"
#include <cstring>

namespace std {

ClientAuthenticator::ClientAuthenticator(ClientHandler * ch) {
	this->client = ch;
}

bool ClientAuthenticator::authenticate(){
	//Determina si el cliente quiere registrarse o logearse
	string auth_type;
	this->client->getAuthType(auth_type);
	if (auth_type.compare(TYPE_LOGIN) == 0)
		return login();
	else /*if (auth_type.compare(TYPE_REGISTER) == 0)*/
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
