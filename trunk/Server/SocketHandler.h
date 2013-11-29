/*
 * SocketListenerHandler.h
 *
 *  Created on: 03/10/2013
 *      Author: juan
 */

#ifndef SOCKETLISTENERHANDLER_H_
#define SOCKETLISTENERHANDLER_H_

#include "../libs/wrappers/Thread.h"
#include "../libs/database/MyDatabase.h"
#include <arpa/inet.h>

class Lobby;

class SocketHandler: public Thread {
	MyDatabase * db;

	Lobby * lobby;
	/*
	 * port es el puerto del que se escucha.
	 */
	uint16_t port;
	/*
	 * sock_listener es el socket utilizado para escuchar.
	 */
	int * sock_listener;
	/*
	 * addr es el struct con la configuracion de la conexion.
	 */
	struct sockaddr_in * addr;
	/*
	 * aceptar_conex indica si se siguen aceptando conexiones luego de procesar
	 * la actual o si hay que detenerse.
	 */
	bool keep_accepting;
	/*
	 * run es heredado de Thread. Espera por una nueva conexion, cuando se
	 * conecta un nuevo cliente llama a procesarCliente, luego cierra la
	 * conexion.
	 */
	void run();
	/*
	 * addClient crea un nuevo FormattedSocket y ClientHandler por cada cliente
	 * que intenta conectarse por el server, identificandolo previamente.
	 */
	void addClient(int & new_client);

public:
	SocketHandler(struct sockaddr_in * addr, Lobby * lob, MyDatabase * data);
	uint16_t getPort();
	void setListeningMode();
	/*
	 * stopAccepting saltea el accept actual y cierra el socket.
	 */
	void stopAccepting();
	virtual ~SocketHandler();
};

#endif /* SOCKETLISTENERHANDLER_H_ */
