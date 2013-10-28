/*
 * MsgInterpreter.h
 *
 *  Created on: 27/10/2013
 *      Author: juan
 */

#ifndef MSGINTERPRETER_H_
#define MSGINTERPRETER_H_

#include "client_Client.h"
#include <string>

namespace std {

class MsgInterpreter {
	Client* client;

	void exitRoom();

public:
	MsgInterpreter(Client * c);
	void interpret(string s); //metodo de ifs anidados
	virtual ~MsgInterpreter();
};

} /* namespace std */
#endif /* MSGINTERPRETER_H_ */
