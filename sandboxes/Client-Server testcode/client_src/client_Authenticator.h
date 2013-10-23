/*
 * Authenticator.h
 *
 *  Created on: 21/10/2013
 *      Author: juan
 */

#ifndef AUTHENTICATOR_H_
#define AUTHENTICATOR_H_

#include "client_Client.h"

namespace std {

class Authenticator {
	Client * client;
	bool verificateMessage(const char * msg, size_t msg_size);
	bool receiveAuthVerif();
	void sendAuth(char * user, size_t u_size, char * passwd, size_t p_size);
	void sendAuthType(char * auth_type, size_t size);

public:
	Authenticator(Client * c);
	bool sendIds(char* user, char* passwd, char * auth_type);
	virtual ~Authenticator();
};

} /* namespace std */
#endif /* AUTHENTICATOR_H_ */
