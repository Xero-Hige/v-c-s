/*
 * ServerListener.h
 *
 *  Created on: 04/11/2013
 *      Author: juan
 */

#ifndef SERVERLISTENER_H_
#define SERVERLISTENER_H_

#include "../../libs/wrappers/Thread.h"
#include "../../libs/wrappers/Socket.h"
#include "ClientMsgInterpreter.h"

namespace std {

class ServerListener : public Thread {
	Socket * sock;
	ClientMsgInterpreter * msg_int;
	bool keep_listening;
	void run();

public:
	ServerListener(Socket * s, ClientMsgInterpreter * c);
	void notifyCommunicationStart();
	void notifyCommunicationEnd();
	virtual ~ServerListener();
};

} /* namespace std */
#endif /* SERVERLISTENER_H_ */
