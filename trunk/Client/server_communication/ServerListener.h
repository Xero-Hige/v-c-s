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
	ServerListener(Server_Connector * sc);
	virtual ~ServerListener();
};

//Para poner en el main: BORRAR ESTE COMMENT
//new Server_connector sc;
//new ServerListener(sc);

#endif /* SERVERLISTENER_H_ */
