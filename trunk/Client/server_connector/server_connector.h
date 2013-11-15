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
#include "../../libs/communication_protocol/FormattedSocket.h"

namespace std {

class Server_Connector {
	friend class AuthenticationService;

	Authenticator auth;
	FormattedSocket * sock;//socket file descriptor

	bool exit_char_pressed;

	void getMatchmaking(string & mm);
	void getRoomId(string & id);
	void useUserDefinedMatchmaking();
	void useDefaultMatchmaking();

public:
	/*
	 * ctor de cliente, se le pasa como param el ip al que se quiere conectar y el
	 * puerto.
	 */
	Server_Connector();
	/*
	 * connectServer intenta conectar el cliente al servidor. Si hubo un problema
	 * errcode contiene el valor 1, si se logro conectar no se modifica.
	 */
	void connectServer(string username, string passwd, string a_type);
	int makeConnection(string ip, int port);
	void enterRoom();
	void exitCharPressed();
	void communicate();
	/*
	 * closeConnection cierra el socket utilizado para la conex.
	 */
	void closeConection();
	virtual ~Server_Connector();
};

} /* namespace std */
#endif /* CLIENT_H_ */
