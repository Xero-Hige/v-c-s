/*
 * ClientHandler.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef CLIENTHANDLER_H_
#define CLIENTHANDLER_H_
#include "../common_src/common_Thread.h"
#include "../common_src/common_MsgConstants.h"
#include "../common_src/common_Socket.h"
#include <stdlib.h>
#include <string>

namespace std {

class Room; //Por la refs circulares...
class Lobby;

class ClientHandler : public Thread, public Socket {
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
