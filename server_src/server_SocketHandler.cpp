/*
 * SocketListenerHandler.cpp
 *
 *  Created on: 03/10/2013
 *      Author: juan
 */

#include "server_SocketHandler.h"
#include <unistd.h> //close
#include <iostream>
#include <sstream>
#include <string>
#include "../common_src/common_BigEndianProtocol.h"

namespace std {

int* crearSocket(){
	int * sockfd = new int();
	(*sockfd) = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM = TCP
	int bla = 1;
	setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &bla, sizeof(int));
	if (*sockfd == -1) cerr << "error" << endl;
	return sockfd;
}

SocketHandler::SocketHandler (struct sockaddr_in * addr){
	//Se crea el socket
	int * sck = crearSocket();
	this->sock_listener = sck;
	//getPort es valido solo cuando se crea, desp de acceptar una
	//conexion cambia el numero del port
	this->port = ntohs(addr->sin_port);
	this->addr = addr;
	this->aceptar_conex = true;
	//bindeo, asocia sockaddr con el socket
	bind(*sock_listener, (struct sockaddr *)addr, sizeof(struct sockaddr));
}

void SocketHandler::run(){
	while (aceptar_conex){
		unsigned int cli_len = sizeof(*(this->addr));
		int new_cli = accept(*sock_listener, (struct sockaddr*) this->addr, &cli_len);
		if (new_cli >= 0){
			procesarCliente(new_cli);
			close(new_cli);
		}
	}
}

void SocketHandler::procesarCliente(int & sock){

}

int SocketHandler::socketSend
(const void * buf, size_t length, int & sock){
	unsigned bytes_enviados = 0;
	//Solo si no se envio nada reenvia. Esto es para evitar que se cuelgue
	//(el cliente) cuando el send del server ocurre antes que el receive
	//del cliente
	while (bytes_enviados == 0){
		bytes_enviados = send(sock, buf, length, 0);
	}
	return bytes_enviados;
}

int SocketHandler::socketReceive(void * buf, size_t length, int & sock){
	return recv(sock, buf, length, 0);
}

uint16_t SocketHandler::getPort(){
	return this->port;
}

int* SocketHandler::getSockListener(){
	return sock_listener;
}

void SocketHandler::dejarDeAceptarConex(){
	this->aceptar_conex = false;
	shutdown(*sock_listener, 2); //salta el accept() actual
	close(*sock_listener);
}

SocketHandler::~SocketHandler() {
	// TODO Auto-generated destructor stub
	delete addr;
	delete sock_listener;
}

} /* namespace std */
