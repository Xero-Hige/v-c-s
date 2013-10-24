/*
 * ServerHandler.h
 *
 *  Created on: 24/10/2013
 *      Author: juan
 */

#ifndef SERVERHANDLER_H_
#define SERVERHANDLER_H_

namespace std {

class ServerHandler {
	int socket;

public:
	ServerHandler(int sockfd);
	virtual ~ServerHandler();
};

} /* namespace std */
#endif /* SERVERHANDLER_H_ */
