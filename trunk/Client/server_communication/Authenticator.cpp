/*
 * Authenticator.cpp
 *
 *  Created on: 21/10/2013
 *      Author: juan
 */

#include "Authenticator.h"
#include "../../libs/messages/MsgConstants.h"
#include "../../libs/communication_protocol/BigEndianProtocol.h"
#include <cstring>

Authenticator::Authenticator() {
}

bool Authenticator::authenticate
(Server_Connector * c, string user, string passwd, string auth_type){
	as.setServerConnector(c);
	as.setAuthType(auth_type);
	as.setUser(user);
	as.setPasswd(passwd);
	//as.start();
	return as.authenticate();
}

Authenticator::~Authenticator() {
}
