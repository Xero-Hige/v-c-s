/*
 * Client.h
 *
 *  Created on: 29/09/2013
 *      Author: juan
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include <stdlib.h>
#include <string>
#include <inttypes.h>
#include "../../libs/wrappers/Socket.h"

namespace std {

class Client {
	friend class Authenticator;

	Socket * sock;//socket file descriptor

	void getMatchmaking(string & mm);
	void getRoomId(string & id);
	void useUserDefinedMatchmaking();
	void useDefaultMatchmaking();

public:
	/*
	 * ctor de cliente, se le pasa como param el ip al que se quiere conectar y el
	 * puerto.
	 */
	Client();
	/*
	 * connectServer intenta conectar el cliente al servidor. Si hubo un problema
	 * errcode contiene el valor 1, si se logro conectar no se modifica.
	 */
	void connectServer(int & errcode, string username, string passwd, string a_type);
	int makeConnection(string ip, int port);
	void enterRoom();
	void communicate();
	int recvMsg(string msg);
	int sendMsg(string msg);
	/*
	 * closeConnection cierra el socket utilizado para la conex.
	 */
	void closeConection();
	virtual ~Client();
};

} /* namespace std */
#endif /* CLIENT_H_ */
