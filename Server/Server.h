/*
 * Server.h
 *
 *  Created on: 29/09/2013
 *      Author: juan
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <stdlib.h>
#include <arpa/inet.h>
#include <vector>
#include "../libs/wrappers/Thread.h"
#include "../libs/database/MyDatabase.h"

class SocketHandler;
class Lobby;

class Server {
	MyDatabase db;
	/*
	 * sock_listeners contiene todos threads de cada socket que escucha el serv.
	 */
	std::vector<SocketHandler*> * sock_listeners;
	/*
	 * crearPuertosDeEscucha recibe una lista de puertos donde el server va a
	 * escuchar (determinados por el usuario) y crea un SocketListenerHandler
	 * por cada uno de ellos. A cada SLH creado lo agrega a la lista
	 * sock_listeners.
	 */
	void createListeningPorts(std::vector<int> * list_puertos, Lobby * lob);

public:
	/*
	 * ctor del server, recibe un CoutHandler para emitir los mensajes por consola.
	 * El mismo va a ser usado por los SocketListenerHandler.
	 */
	explicit Server();
	/*
	 * serverListen indica a cada puerto que el server haya abierto que escuche.
	 */
	void serverListen(std::vector<int> * list_puertos, Lobby * lob);
	/*
	 * acceptConnections indica a cada SocketListenerHandler de la lista
	 *  que se ejecute (cada uno en un thread distinto).
	 */
	void acceptConnections();
	/*
	 * dejarDeAceptarConex indica a cada puerto que deje de aceptar conexiones, y
	 * espera a que los hilos de los sockets terminen, uniendose con el actual.
	 */
	void dejarDeAceptarConex();
	virtual ~Server();
};

//Agrega la funcion contiene a vector. Indica si el vector contiene un T segun
//el criterio de comparador.
template < class T >
bool contiene(std::vector<T*> * vec, T * v, bool (*comparador)(T * v, T * a)){
	for (unsigned i = 0; i < vec->size(); i++){
		if (comparador(v, vec->at(i))) return true;
	}
	return false;
}

#endif /* SERVER_H_ */
