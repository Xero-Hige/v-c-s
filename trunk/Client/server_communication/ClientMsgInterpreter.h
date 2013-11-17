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

class ClientMsgInterpreter : public MsgInterpreter{
	Server_Connector* client;
	void exitRoom();
	void exitCharPressed();
	void interpretParticularMsg(string s);
public:
	ClientMsgInterpreter(Server_Connector * c);
	virtual ~ClientMsgInterpreter();
};

#endif /* MSGINTERPRETER_H_ */
