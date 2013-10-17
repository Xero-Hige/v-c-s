/*
 * SocketListenerHandler.h
 *
 *  Created on: 03/10/2013
 *      Author: juan
 */

#ifndef SOCKETLISTENERHANDLER_H_
#define SOCKETLISTENERHANDLER_H_

#include "../common_src/common_Thread.h"
#include <arpa/inet.h>

namespace std {

class SocketHandler: public Thread {
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
	bool aceptar_conex;
	/*
	 * run es heredado de Thread. Espera por una nueva conexion, cuando se
	 * conecta un nuevo cliente llama a procesarCliente, luego cierra la
	 * conexion.
	 */
	void run();
	/*
	 * procesarCliente corre todas las funciones que completan la transferencia de
	 * datos con el cliente, es decir, envia el mensaje de bienvenida, recibe el
	 * archivo y envia el mensaje de verificacion.
	 */
	void procesarCliente(int & sock);

public:
	SocketHandler(struct sockaddr_in * addr);
	/*
	 * socketSend envia los datos de buf a traves del socket.
	 */
	int socketSend(const void * buf, size_t length, int & sock);
	/*
	 * socketReceive recibe datos y los almacena en buf.
	 */
	int socketReceive(void * buf, size_t length, int & sock);
	int* getSockListener();
	uint16_t getPort();
	/*
	 * dejarDeAceptarConex saltea el accept actual y cierra el socket.
	 */
	void dejarDeAceptarConex();
	virtual ~SocketHandler();
};

} /* namespace std */
#endif /* SOCKETLISTENERHANDLER_H_ */
