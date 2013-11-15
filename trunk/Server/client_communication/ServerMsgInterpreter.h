/*
 * ServerMsgInterpreter.h
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#ifndef SERVERMSGINTERPRETER_H_
#define SERVERMSGINTERPRETER_H_

#include <string>
#include "../../libs/messages/MsgInterpreter.h"
#include "ClientHandler.h"

namespace std {

class ServerMsgInterpreter : public MsgInterpreter {
	ClientHandler * client;
	void exitRoom();
	void exitCharPressed();

public:
	ServerMsgInterpreter(ClientHandler* c);
	virtual ~ServerMsgInterpreter();
};

} /* namespace std */
#endif /* MSGINTERPRETER_H_ */