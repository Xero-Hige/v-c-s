/*
 * Authenticator.h
 *
 *  Created on: 21/10/2013
 *      Author: juan
 */

#ifndef AUTHENTICATOR_H_
#define AUTHENTICATOR_H_

#include "../server_connector/server_connector.h"

namespace std {

class Authenticator {
	Server_Connector * client;
	bool verificateMessage(string msg);
	bool receiveAuthVerif();

public:
	Authenticator(Server_Connector * c);
	bool sendIds(string & user, string & passwd, string & auth_type);
	virtual ~Authenticator();
};

} /* namespace std */
#endif /* AUTHENTICATOR_H_ */
