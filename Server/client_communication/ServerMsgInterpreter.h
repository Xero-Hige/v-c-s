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
	/*
	 * exitRoom, exitCharPressed y closeConnection llaman a los respectivos
	 *  metodos del ClientHandler.
	 */
	void closeConnection();
	void exitRoom();
	void exitCharPressed();
	void interpretParticularMsg(std::string s);
public:
	explicit ServerMsgInterpreter(ClientHandler* c);
	virtual ~ServerMsgInterpreter();
};

#endif /* MSGINTERPRETER_H_ */
