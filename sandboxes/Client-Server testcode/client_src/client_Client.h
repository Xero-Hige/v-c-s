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

namespace std {

class Client {
	friend class Authenticator;

	string ip;
	int port;
	int sockfd;//socket file descriptor
	/*
	 * clientSend envia el contenido de buf a traves de la conexion establecida.
	 * length es el tamanho del buffer.
	 */
	int clientSend(char * buf, size_t length);
	/*
	 * clientReceive recibe un buffer entrante.
	 */
	int clientReceive(char * buf, size_t length);

	void getConnectionType(string & a_type);
	void getPasswd(string & passwd);
	void getUsername(string & user);
	int makeConnection();

public:
	/*
	 * ctor de cliente, se le pasa como param el ip al que se quiere conectar y el
	 * puerto.
	 */
	Client(string ip, int port);
	/*
	 * connectServer intenta conectar el cliente al servidor. Si hubo un problema
	 * errcode contiene el valor 1, si se logro conectar no se modifica.
	 */
	void connectServer(int & errcode);
	void enviarMsg();
	/*
	 * closeConnection cierra el socket utilizado para la conex.
	 */
	void closeConection();
	virtual ~Client();
};

} /* namespace std */
#endif /* CLIENT_H_ */
