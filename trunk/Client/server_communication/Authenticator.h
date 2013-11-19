/*
 * Authenticator.h
 *
 *  Created on: 21/10/2013
 *      Author: juan
 */

#ifndef AUTHENTICATOR_H_
#define AUTHENTICATOR_H_

#include "../server_connector/server_connector.h"
#include "AuthenticationService.h"

#include <string>

class Authenticator {
	AuthenticationService as;

public:
	Authenticator();
	bool authenticate(Server_Connector * c, std::string u, std::string passwd, std::string type);
	virtual ~Authenticator();
};

#endif /* AUTHENTICATOR_H_ */
