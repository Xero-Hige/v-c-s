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
	std::string password;
	Authenticator auth;
	FormattedSocket * sock; //socket file descriptor
	bool exit_char_pressed;

	/*
	 * getMatchmaking le pide al usuario de que modo quiere obtener su room.
	 */
	void getMatchmaking(std::string & mm);
	/*
	 * getRoomId le pide al usuario el room al que se quiere conectar.
	 */
	void getRoomId(std::string & id);
	/*
	 * useUserDefinedMatchmaking envia al servidor el room al que se quiere conectar
	 */
	void useUserDefinedMatchmaking();
	/*
	 * useDefaultMatchmaking se conecta a un room aleatorio.
	 */
	void useDefaultMatchmaking();

public:
	Server_Connector();
	/*
	 * connectServer intenta autenticar el cliente en el servidor. a_type es el modo
	 * de autenticacion que se requiere (login/register).
	 */
	bool connectServer(std::string user, std::string passwd, std::string a_type);
	/*
	 * makeConnection se conecta con el ip y puerto indicado.
	 */
	int makeConnection(std::string ip, int port);
	/*
	 * sendMsg envia el mensaje 'msg' firmado por HMAC.
	 */
	int sendMsg(std::string msg);
	/*
	 * recvMsg recibe un mensaje del servidor.
	 */
	int recvMsg(std::string & msg);
	/*
	 * enterRoom le pide al usuario el modo de conectarse a un room y lo envia al
	 * server.
	 */
	void enterRoom();
	/*
	 * exitCharPressed setea que se presiono al caracter de salida. communicate()
	 * lo utiliza.
	 */
	void exitCharPressed();
	/*
	 * DEBUG: communicate se usa para debuggear. Le pide al usuario la cadena de
	 * caracteres que quiere enviar al servidor y la envia.
	 */
	void communicate();
	/*
	 * closeConnection cierra el socket utilizado para la conex.
	 */
	void closeConection();
	FormattedSocket * getSocket();
	virtual ~Server_Connector();
};

#endif /* SERVER_CONNECTOR_H */
