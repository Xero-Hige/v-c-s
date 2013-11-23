/*
 * Client.h
 *
 *  Created on: 29/09/2013
 *      Author: juan
 */

#ifndef SERVER_CONNECTOR_H_
#define SERVER_CONNECTOR_H_
#include <stdlib.h>
#include <string>
#include "../../libs/communication_protocol/FormattedSocket.h"
#include "../server_communication/Authenticator.h"


class Server_Connector {
	Authenticator auth;
	FormattedSocket * sock; //socket file descriptor

	bool exit_char_pressed;

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
	 * connectServer intenta conectar el cliente al servidor.
	 */
	bool connectServer(std::string username, std::string passwd, std::string a_type);
	int makeConnection(std::string ip, int port);
	bool getAuthEnded();
	int sendMsg(std::string msg);
	int recvMsg(std::string & msg);
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

#endif /* SERVER_CONNECTOR_H */
