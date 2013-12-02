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
#include "../../libs/game_messages/message_reader.h"
#include "../../libs/game_messages/game_message_reader.h"

#include <string>

class Backend;

class ClientMsgInterpreter : public MsgInterpreter{
	Server_Connector* client;
	Backend * backend;
	MessageReader msg_reader;
	GameMessageReader game_msg_reader;

	/*
	 * Los metodos de esta clase interpretan el mensaje devuelto por el servidor
	 * y llaman a los metodos que correspondan.
	 */
	void closeConnection();
	void exitRoom();
	void exitCharPressed();
	void interpretParticularMsg(std::string s);
public:
	ClientMsgInterpreter(Server_Connector * c, Backend * b);
	virtual ~ClientMsgInterpreter();
};

#endif /* MSGINTERPRETER_H_ */
