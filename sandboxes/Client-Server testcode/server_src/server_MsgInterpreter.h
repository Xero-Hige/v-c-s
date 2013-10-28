/*
 * MsgInterpreter.h
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#ifndef MSGINTERPRETER_H_
#define MSGINTERPRETER_H_

#include "server_ClientHandler.h"
#include <string>

namespace std {

class MsgInterpreter {
	ClientHandler * client;
	void exitRoom();

public:
	MsgInterpreter(ClientHandler* c);
	bool interpret(string s);
	virtual ~MsgInterpreter();
};

} /* namespace std */
#endif /* MSGINTERPRETER_H_ */
