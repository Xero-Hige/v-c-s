/*
 * ClientAuthenticator.h
 *
 *  Created on: 23/10/2013
 *      Author: juan
 */

#ifndef CLIENTAUTHENTICATOR_H_
#define CLIENTAUTHENTICATOR_H_

#include "server_ClientHandler.h"

namespace std {

class ClientAuthenticator {
	ClientHandler * client;

	bool login();
	bool registrate();

public:
	ClientAuthenticator(ClientHandler * ch);
	bool authenticate();
	virtual ~ClientAuthenticator();
};

} /* namespace std */
#endif /* CLIENTAUTHENTICATOR_H_ */
