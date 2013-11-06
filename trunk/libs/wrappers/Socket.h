/*
 * Socket.h
 *
 *  Created on: 03/11/2013
 *      Author: juan
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include <string>
#include <unistd.h> //close
#include <arpa/inet.h>

namespace std {

class Socket {
	int socket;
	int socketSend(char * buf, size_t length);
	int socketRecv(char * buf, size_t length);

public:
	Socket(int sockfd);
	int sendMsg(string msg);
	int recvMsg(string & msg, size_t length);
	int getSocket();
	void socketShutdown();
	void closeConnection();
	virtual ~Socket();
};

} /* namespace std */
#endif /* SOCKET_H_ */
