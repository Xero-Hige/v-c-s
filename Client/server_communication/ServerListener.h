/*
 * ServerListener.h
 *
 *  Created on: 04/11/2013
 *      Author: juan
 */

#ifndef SERVERLISTENER_H_
#define SERVERLISTENER_H_

#include "../../libs/wrappers/Thread.h"
#include "../../libs/communication_protocol/FormattedSocket.h"
#include "ClientMsgInterpreter.h"

class Backend;

class ServerListener : public Thread {
	FormattedSocket * socket;
	ClientMsgInterpreter msg_int;
	bool keep_listening;
	/*
	 * run escucha los mensajes que envia el servidor y se los entrega a
	 * ClientMsgInterpreter para que decida que hacer.
	 */
	void run();

public:
	ServerListener(Server_Connector * sc, Backend * b);
	virtual ~ServerListener();
};

#endif /* SERVERLISTENER_H_ */
