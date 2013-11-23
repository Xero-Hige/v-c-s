/*
 * Authenticator.h
 *
 *  Created on: 21/10/2013
 *      Author: juan
 */

#ifndef AUTHENTICATOR_H_
#define AUTHENTICATOR_H_

#include "../../libs/communication_protocol/FormattedSocket.h"

#include <string>

class Authenticator {
	FormattedSocket * sock;
	bool verificateMessage(std::string msg);
	bool receiveAuthVerif();

public:
	Authenticator();
	void setSocket(FormattedSocket * s);
	bool authenticate(std::string u, std::string passwd, std::string type);
	virtual ~Authenticator();
};

#endif /* AUTHENTICATOR_H_ */
