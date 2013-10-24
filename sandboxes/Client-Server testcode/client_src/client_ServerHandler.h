/*
 * ServerHandler.h
 *
 *  Created on: 24/10/2013
 *      Author: juan
 */

#ifndef SERVERHANDLER_H_
#define SERVERHANDLER_H_

#include <stdlib.h>
#include <string>

namespace std {

class ServerHandler {
	int socket;
	int clientSend(char * buf, size_t length);
	int clientReceive(char * buf, size_t length);

public:
	ServerHandler(int sockfd);
	int sendMsg(string msg);
	int recvMsg(string & msg);
	int& getSocket();
	void closeConnection();
	virtual ~ServerHandler();
};

} /* namespace std */
#endif /* SERVERHANDLER_H_ */
