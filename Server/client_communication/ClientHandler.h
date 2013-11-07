/*
 * ClientHandler.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef CLIENTHANDLER_H_
#define CLIENTHANDLER_H_
#include "../../libs/wrappers/Thread.h"
#include "../../libs/messages/MsgConstants.h"
#include "../../libs/communication_protocol/FormattedSocket.h"
#include <stdlib.h>
#include <string>

namespace std {

class Room; //Por la refs circulares...
class Lobby;

class ClientHandler : public Thread, public FormattedSocket {
	Room * room;

	Lobby * lobby;

	bool keep_communicating;

	void run();

public:
	explicit ClientHandler(int sock, Lobby * lob);

	void setRoom(Room * r);

	void exitRoom();

	void getIds(string & user, string & passwd);

	void sendIdsVerifMsg();

	virtual ~ClientHandler();
};

} /* namespace std */
#endif /* CLIENTHANDLER_H_ */
