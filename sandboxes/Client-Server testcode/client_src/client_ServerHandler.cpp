/*
 * ServerHandler.cpp
 *
 *  Created on: 24/10/2013
 *      Author: juan
 */

#include "client_ServerHandler.h"

namespace std {

ServerHandler::ServerHandler(int sockfd) {
	this->socket = sockfd;
}

ServerHandler::~ServerHandler() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
