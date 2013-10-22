/*
 * SocketListenerHandler.h
 *
 *  Created on: 03/10/2013
 *      Author: juan
 */

#ifndef SOCKETLISTENERHANDLER_H_
#define SOCKETLISTENERHANDLER_H_

#include "../common_src/common_Thread.h"
#include "server_Lobby.h"
#include <arpa/inet.h>

namespace std {

class SocketHandler: public Thread {
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

	bool authenticateClient(ClientHandler * ch);
	void addClient(int new_client);

public:
	SocketHandler(struct sockaddr_in * addr, Lobby * lob);
	uint16_t getPort();
	void setListeningMode();
	/*
	 * stopAccepting saltea el accept actual y cierra el socket.
	 */
	void stopAccepting();
	virtual ~SocketHandler();
};

} /* namespace std */
#endif /* SOCKETLISTENERHANDLER_H_ */
