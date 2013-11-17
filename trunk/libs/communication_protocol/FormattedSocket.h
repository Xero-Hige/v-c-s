/*
 * FormattedSocket.h
 *
 *  Created on: 05/11/2013
 *      Author: juan
 */

#ifndef FORMATTEDSOCKET_H_
#define FORMATTEDSOCKET_H_

#include "../wrappers/Socket.h"
#include "BigEndianProtocol.h"
#include <string>

class FormattedSocket : public Socket {

public:
	FormattedSocket(int sockfd);
	int sendMsg(std::string msg);
	int recvMsg(std::string & msg);
	virtual ~FormattedSocket();
};

#endif /* FORMATTEDSOCKET_H_ */
