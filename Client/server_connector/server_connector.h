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
#include "../server_communication/Authenticator.h"

class Server_Connector {
	friend class AuthenticationService;

	Authenticator auth;
	FormattedSocket * sock;//socket file descriptor

	bool exit_char_pressed;

	bool logged;
	bool auth_ended;

	void getMatchmaking(std::string & mm);
	void getRoomId(std::string & id);
	void useUserDefinedMatchmaking();
	void useDefaultMatchmaking();
	void setLogged(bool b);
	void setAuthEnded(bool b);
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
	void connectServer(std::string username, std::string passwd, std::string a_type);
	int makeConnection(std::string ip, int port);
	bool getAuthEnded();
	bool getLogged();
	void enterRoom();
	void exitCharPressed();
	void communicate();
	/*
	 * closeConnection cierra el socket utilizado para la conex.
	 */
	void closeConection();
	virtual ~Server_Connector();
};

#endif /* CLIENT_H_ */
