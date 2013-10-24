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

class ClientHandler : public Thread {
	int sock;

	void run();

	bool keep_communicating;
	/*
	 * socketSend envia los datos de buf a traves del socket.
	 */
	int socketSend(const void * buf, size_t length);
	/*
	 * socketReceive recibe datos y los almacena en buf.
	 */
	int socketReceive(void * buf, size_t length);

	void getUser(string & user);
	void getPasswd(string & passwd);

public:
	explicit ClientHandler(int sock);

	void getAuthType(string & auth_type);

	void getIds(string & user, string & passwd);

	void sendIdsVerifMsg();

	virtual ~ClientHandler();
};

} /* namespace std */
#endif /* CLIENTHANDLER_H_ */
