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
#include <stdlib.h>
#include <string>

namespace std {

class Room; //Por la refsa circulares...
class Lobby;

class ClientHandler : public Thread {
	Room * room;

	Lobby * lobby;

	bool keep_communicating;

	int sock;

	void run();

	/*
	 * socketSend envia los datos de buf a traves del socket.
	 */
	int socketSend(const void * buf, size_t length);
	/*
	 * socketReceive recibe datos y los almacena en buf.
	 */
	int socketReceive(void * buf, size_t length);

public:
	explicit ClientHandler(int sock, Lobby * lob);

	int recvMsg(string & msg);

	int sendMsg(string msg);

	void setRoom(Room * r);

	void exitRoom();

	void getIds(string & user, string & passwd);

	void sendIdsVerifMsg();

	virtual ~ClientHandler();
};

} /* namespace std */
#endif /* CLIENTHANDLER_H_ */
