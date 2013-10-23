/*
 * Authenticator.cpp
 *
 *  Created on: 21/10/2013
 *      Author: juan
 */

#include "client_Authenticator.h"
#include "../common_src/common_MsgConstants.h"
#include <cstring>

namespace std {

Authenticator::Authenticator(Client * c) {
	this->client = c;
}

bool Authenticator::receiveAuthVerif(){
	return verificateMessage(IDS_VERIF, IDS_VERIF_SIZE);
}

bool Authenticator::verificateMessage(const char * msg, size_t msg_size){
	//Compara si el mensaje que envio el server coincide con 'msg'
	char * req = new char[msg_size];
	char * compare = new char[msg_size];
	strcpy(compare, msg);
	client->clientReceive(req, msg_size);
	if (strcmp(req, compare) == 0) {
		delete[] req;
		delete[] compare;
		return true;
	}
	delete[] req;
	delete[] compare;
	return false;
}

void concatenateUserPassword //result tiene el tamanho u_size + p_size
(char * result, char * user, size_t u_size, char * passwd, size_t p_size){
	for (unsigned i = 0; i < u_size; i++)
		result[i] = user[i];
	for (unsigned i = u_size; i < u_size + p_size; i++)
		result[i] = passwd[i - u_size];
}

void Authenticator::sendAuth
(char * user, size_t u_size, char * passwd, size_t p_size){
	char * msg = new char[u_size + p_size];
	concatenateUserPassword(msg, user, u_size, passwd, p_size);
	this->client->clientSend(msg, u_size + p_size);
	delete[] msg;
}

void Authenticator::sendAuthType(char * auth_type, size_t size){
	this->client->clientSend(auth_type, TYPE_SIZE);
}

bool Authenticator::sendIds
(char* user, char* passwd, char* auth_type){
	this->sendAuthType(auth_type, TYPE_SIZE);
	this->sendAuth(user, IDS_USERNAME_SIZE, passwd, IDS_PASSWD_SIZE);
	if (this->receiveAuthVerif()) return true;
	return false;
}

Authenticator::~Authenticator() {
}

} /* namespace std */
