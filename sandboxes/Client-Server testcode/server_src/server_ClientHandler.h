/*
 * ClientHandler.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef CLIENTHANDLER_H_
#define CLIENTHANDLER_H_
#include "../common_src/common_Thread.h"
#include <stdlib.h>

namespace std {

class ClientHandler : public Thread {
	int sock;

	void run();

	bool keep_communicating;

public:
	explicit ClientHandler(int sock);
	/*
	 * socketSend envia los datos de buf a traves del socket.
	 */
	int socketSend(const void * buf, size_t length);
	/*
	 * socketReceive recibe datos y los almacena en buf.
	 */
	int socketReceive(void * buf, size_t length);
	virtual ~ClientHandler();
};

} /* namespace std */
#endif /* CLIENTHANDLER_H_ */