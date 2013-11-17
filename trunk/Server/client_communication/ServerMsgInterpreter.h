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

class ServerMsgInterpreter : public MsgInterpreter {
	ClientHandler * client;
	void exitRoom();
	void exitCharPressed();
	void interpretParticularMsg(std::string s);
public:
	ServerMsgInterpreter(ClientHandler* c);
	virtual ~ServerMsgInterpreter();
};

#endif /* MSGINTERPRETER_H_ */
