/*
 * ClientAuthenticator.cpp
 *
 *  Created on: 23/10/2013
 *      Author: juan
 */

#include "ClientAuthenticator.h"
#include "../../libs/messages/MsgConstants.h"
#include <cstring>
#include <string>

ClientAuthenticator::ClientAuthenticator
(FormattedSocket * s, MyDatabase* data, ClientHandler * ch) {
	this->db = data;
	this->client_handler = ch;
	this->sock = s;
}

bool ClientAuthenticator::authenticate(){
	//Determina si el cliente quiere registrarse o logearse
	std::string s_auth_type;
	sock->recvMsg(s_auth_type);
	int auth_type = atoi(s_auth_type.c_str());
	if(auth_type == TYPE_LOGIN)
		return login();
	else if (auth_type == TYPE_REGISTER)
		return registerUser();
	else
		return false;
}

void ClientAuthenticator::sendIdsVerifMsg(bool success){
	if (success){
		std::string msg(IDS_VERIF);
		sock->sendMsg(msg);
	} else {
		std::string msg(IDS_FAIL);
		sock->sendMsg(msg);
	}
}

void ClientAuthenticator::getIds(std::string & user, std::string & passwd){
	sock->recvMsg(user);
	sock->recvMsg(passwd);
	this->clients_password = passwd;
	this->clients_username = user;
}


bool ClientAuthenticator::registerUser(){
	std::string user, passwd;
	this->getIds(user, passwd);
	int i = db->registerUser(user, passwd, 0); //0 es el nivel inicial
	if (i >= 0){
		this->sendIdsVerifMsg(true);
		return true;
	} else {
		this->sendIdsVerifMsg(false);
		return false;
	}
}

bool ClientAuthenticator::login(){
	std::string user, passwd;
	this->getIds(user, passwd);
	//Realizo el chequeo de ids
	std::string real_passwd;
	db->requestPasswd(user, real_passwd);
	if (real_passwd.compare(passwd) == 0){
		this->sendIdsVerifMsg(true);
		return true;
	} else {
		this->sendIdsVerifMsg(false);
		return false;
	}
}

void ClientAuthenticator::setIdsTo(ClientHandler * ch){
	ch->setPassword(this->clients_password);
	ch->setUserid(this->clients_username);
	unsigned level;
	this->db->requestLevel(clients_username, level);
	ch->setLevel(level);
}

ClientAuthenticator::~ClientAuthenticator() {
	// TODO Auto-generated destructor stub
}

