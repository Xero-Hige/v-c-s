/*
 * AuthenticationService.h
 *
 *  Created on: 13/11/2013
 *      Author: juan
 */

#ifndef AUTHENTICATIONSERVICE_H_
#define AUTHENTICATIONSERVICE_H_

#include "../../libs/wrappers/Thread.h"
#include "../backend/backend.h"
#include <string>

namespace std {

class AuthenticationService : public Thread{
	Backend * be;
	Server_Connector * c;
	string user;
	string passwd;
	string auth_type;
	bool verificateMessage(string msg);
	bool receiveAuthVerif();

public:
	void setBackend(Backend * be);
	void setServerConnector(Server_Connector * c);
	void setUser(string s);
	void setPasswd(string s);
	void setAuthType(string s);
	AuthenticationService();
	void run();
	void authenticate();
	virtual ~AuthenticationService();
};

} /* namespace std */
#endif /* AUTHENTICATIONSERVICE_H_ */
