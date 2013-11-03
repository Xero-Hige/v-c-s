/*
 * ClientMsgInterpreter.h
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#ifndef CLIENTMSGINTERPRETER_H_
#define CLIENTMSGINTERPRETER_H_

#include "../common_src/common_MsgInterpreter.h"
#include "client_Client.h"

namespace std {

class ClientMsgInterpreter : public MsgInterpreter{
	Client* client;

	void exitRoom();

public:
	ClientMsgInterpreter(Client * c);
	virtual ~ClientMsgInterpreter();
};

} /* namespace std */
#endif /* MSGINTERPRETER_H_ */
