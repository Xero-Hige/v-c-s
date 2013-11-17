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

class ClientAuthenticator {
	FormattedSocket sock;

	bool login();
	bool registrate();

public:
	ClientAuthenticator(int socket);
	bool authenticate();
	void sendIdsVerifMsg();
	void getIds(std::string & user, std::string & passwd);
	virtual ~ClientAuthenticator();
};

#endif /* CLIENTAUTHENTICATOR_H_ */
