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
	char auth_type[TYPE_SIZE];
	this->client->getAuthType(auth_type, TYPE_SIZE);
	if (strcmp(auth_type, TYPE_LOGIN) == 0)
		return login();
	else /*if (strcmp(auth_type, TYPE_REGISTER) == 0)*/
		return registrate();
}

bool ClientAuthenticator::registrate(){
	//todo
	char ids[IDS_RESPONSE_SIZE];
	client->getIds(ids, IDS_RESPONSE_SIZE);
	//DO SHIT
	client->sendIdsVerifMsg();
	return true;
}

bool ClientAuthenticator::login(){
	char ids[IDS_RESPONSE_SIZE];
	client->getIds(ids, IDS_RESPONSE_SIZE);
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
