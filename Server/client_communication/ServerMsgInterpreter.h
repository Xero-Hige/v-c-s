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
#include "../../libs/game_messages/game_message_reader.h"
#include "../../libs/game_messages/message_reader.h"

class ServerMsgInterpreter : public MsgInterpreter {
	ClientHandler * client;
	MessageReader msg_reader;
	GameMessageReader game_msg_reader;

	void manageBoard();
	void manageReplacements();
	void manageLevel();
	void closeConnection();
	void exitRoom();
	void exitCharPressed();
	void interpretParticularMsg(std::string s);
public:
	explicit ServerMsgInterpreter(ClientHandler* c);
	virtual ~ServerMsgInterpreter();
};

#endif /* MSGINTERPRETER_H_ */
