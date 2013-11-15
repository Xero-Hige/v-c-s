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

class AuthenticationService : public Thread{
	Backend * be;
	Server_Connector * c;
	std::string user;
	std::string passwd;
	std::string auth_type;
	bool verificateMessage(std::string msg);
	bool receiveAuthVerif();

public:
	void setBackend(Backend * be);
	void setServerConnector(Server_Connector * c);
	void setUser(std::string s);
	void setPasswd(std::string s);
	void setAuthType(std::string s);
	AuthenticationService();
	void run();
	void authenticate();
	virtual ~AuthenticationService();
};

#endif /* AUTHENTICATIONSERVICE_H_ */
