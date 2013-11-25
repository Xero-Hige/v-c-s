/*
 * ClientAuthenticator.h
 *
 *  Created on: 23/10/2013
 *      Author: juan
 */

#ifndef CLIENTAUTHENTICATOR_H_
#define CLIENTAUTHENTICATOR_H_

#include "ClientHandler.h"
#include "../../libs/communication_protocol/FormattedSocket.h"
#include "../../libs/database/MyDatabase.h"

class ClientAuthenticator {
	std::string clients_password;
	FormattedSocket sock;
	MyDatabase * db;
	bool login();
	bool registrate();

public:
	ClientAuthenticator(int socket, MyDatabase * data);
	bool authenticate();
	void setPasswordTo(ClientHandler * ch);
	void sendIdsVerifMsg();
	void getIds(std::string & user, std::string & passwd);
	virtual ~ClientAuthenticator();
};

#endif /* CLIENTAUTHENTICATOR_H_ */
