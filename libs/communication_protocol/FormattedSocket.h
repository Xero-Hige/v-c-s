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

namespace std {

class FormattedSocket : public Socket {

public:
	FormattedSocket(int sockfd);
	int sendMsg(string msg);
	int recvMsg(string & msg);
	virtual ~FormattedSocket();
};

} /* namespace std */
#endif /* FORMATTEDSOCKET_H_ */
