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
namespace std {

class Authenticator {
	AuthenticationService as;

public:
	Authenticator();
	void authenticate(Server_Connector * c, string u, string passwd, string type);
	virtual ~Authenticator();
};

} /* namespace std */
#endif /* AUTHENTICATOR_H_ */
