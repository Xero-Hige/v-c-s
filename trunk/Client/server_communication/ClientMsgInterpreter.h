/*
 * ClientMsgInterpreter.h
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#ifndef CLIENTMSGINTERPRETER_H_
#define CLIENTMSGINTERPRETER_H_

#include "../../libs/messages/MsgInterpreter.h"
#include "../server_connector/server_connector.h"
#include <string>

class ClientMsgInterpreter : public MsgInterpreter{
	Server_Connector* client;

	/*
	 * Los metodos de esta clase interpretan el mensaje devuelto por el servidor
	 * y llaman a los metodos que correspondan.
	 */

	void exitRoom();
	void interpretParticularMsg(std::string s);
public:
	explicit ClientMsgInterpreter(Server_Connector * c);
	virtual ~ClientMsgInterpreter();
};

#endif /* MSGINTERPRETER_H_ */
