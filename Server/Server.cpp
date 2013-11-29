/*
 * Server.cpp
 *
 *  Created on: 29/09/2013
 *      Author: juan
 */

#include "Server.h"
#include <sys/socket.h> //AF_INET, SOCK_STREAM
#include "SocketHandler.h"
#include "rooms/Lobby.h"
#include <iostream>
#include <vector>
#include <arpa/inet.h> //inet_addr, htons, server_addr
#include <cstring> // memset
#include <sys/types.h> //accept
#include <unistd.h> //close

/*
 * setListener configura el struct sockaddr_in adecuadamente.
 */
void setListener(struct sockaddr_in * cli_addr, int & server_port){
	cli_addr->sin_family = AF_INET;
	cli_addr->sin_port = htons(server_port);
	cli_addr->sin_addr.s_addr = INADDR_ANY; //Se escucha cualquier ip
	//memset deja a la cantidad de bytes indicada en el tercer parametro
	//a los que apunta el primer parametro
	//en el valor del segundo parametro
	memset(&(cli_addr->sin_zero), 0, sizeof(cli_addr->sin_zero));
}

Server::Server(){
	// TODO Auto-generated constructor stub
	sock_listeners = new std::vector<SocketHandler*>();
	this->db.open();
}

/*
 * comparadorPuertos indica si dos listeners son iguales dependiendo del puerto
 * al cual escuchan.
 */
bool comparadorPuertos
(SocketHandler * sh1, SocketHandler * sh2){
	return (sh1->getPort() == sh2->getPort());
}

void Server::createListeningPorts(std::vector<int> * list_puertos, Lobby * lob){
	//Se recorre la lista de puertos.
	for (unsigned i = 0; i < list_puertos->size(); i++){
		int port_actual = list_puertos->at(i);
		//Se crea un nuevo sockaddr
		//Lo libera SocketListenerHandler
		struct sockaddr_in * caddr = new struct sockaddr_in();
		//Se le indica que puerto va a escuchar
		setListener(caddr, port_actual);
		//Se agrega a la lista
		SocketHandler * sh = new SocketHandler(caddr, lob, &db);
		if (contiene(sock_listeners, sh, comparadorPuertos)){
			delete sh;
		} else {
			sock_listeners->push_back(sh);
		}
	}
}

/*
 * serverListen crea una lista de sockets que escuchan en los puertos indicados
 * por 'list_puertos'. Luego los setea en modo escucha.
 */
void Server::serverListen(std::vector<int> * list_puertos, Lobby * lob){
	//Se crean
	this->createListeningPorts(list_puertos, lob);
	for (unsigned i = 0; i < sock_listeners->size(); i++){
		//Obtiene cada socket y lo pone en modo escucha
		(sock_listeners->at(i))->setListeningMode();
	}
}

void Server::acceptConnections(){
	for (unsigned i = 0; i < sock_listeners->size(); i++){
		//Le indico a cada socket de escucha que acepte la conex
		sock_listeners->at(i)->start();
	}
}

void Server::dejarDeAceptarConex(){
	//Le indica a cada socket que deje de aceptar
	for (unsigned i = 0; i < sock_listeners->size(); i++){
		sock_listeners->at(i)->stopAccepting();
		sock_listeners->at(i)->join();
	}
}

Server::~Server(){
	for (unsigned i = 0; i < sock_listeners->size(); i++){
		delete sock_listeners->at(i);
	}
	this->db.close();
	delete sock_listeners;
}
