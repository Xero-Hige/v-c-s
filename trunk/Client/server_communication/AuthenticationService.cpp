/*
 * AuthenticationService.cpp
 *
 *  Created on: 13/11/2013
 *      Author: juan
 */

#include "AuthenticationService.h"
#include "../../libs/messages/MsgConstants.h"
#include "../../libs/communication_protocol/BigEndianProtocol.h"
#include <cstring>
#include <string>

AuthenticationService::AuthenticationService() {
	this->be = NULL;
	this->c = NULL;
}

void AuthenticationService::setBackend(Backend * be){
	this->be = be;
}

void AuthenticationService::setServerConnector(Server_Connector * c){
	this->c = c;
}
void AuthenticationService::setUser(string s){
	this->user = s;
}
void AuthenticationService::setPasswd(string s){
	this->passwd = s;
}
void AuthenticationService::setAuthType(string s){
	this->auth_type = s;
}

bool AuthenticationService::receiveAuthVerif(){
	string s(IDS_VERIF);
	return verificateMessage(s);
}

bool AuthenticationService::verificateMessage(string msg){
	//Compara si el mensaje que envio el server coincide con 'msg'
	string recvd_msg;
	c->sock->recvMsg(recvd_msg);
	if (recvd_msg.compare(msg) == 0) {
		return true;
	}
	return false;
}

void AuthenticationService::authenticate(){
	c->sock->sendMsg(auth_type);
	c->sock->sendMsg(user);
	c->sock->sendMsg(passwd);
	if (this->receiveAuthVerif())
		//se autentico
		be->setLogged(true);
	else be->setLogged(false);
	be->setOperationEnded(true);
}

void AuthenticationService::run(){
	this->authenticate();
}

AuthenticationService::~AuthenticationService() {
	// TODO Auto-generated destructor stub
}
