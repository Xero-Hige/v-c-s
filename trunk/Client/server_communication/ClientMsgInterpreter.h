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

namespace std {

class ClientMsgInterpreter : public MsgInterpreter{
	Server_Connector* client;

	void exitRoom();

public:
	ClientMsgInterpreter(Server_Connector * c);
	virtual ~ClientMsgInterpreter();
};

} /* namespace std */
#endif /* MSGINTERPRETER_H_ */
