/*
 * SocketListenerHandler.cpp
 *
 *  Created on: 03/10/2013
 *      Author: juan
 */

#include "SocketHandler.h"
#include "rooms/Lobby.h"
#include "client_communication/ClientAuthenticator.h"
#include <unistd.h> //close
#include <iostream>
#include <sstream>
#include <string>
#include "../libs/communication_protocol/BigEndianProtocol.h"
#include "../libs/messages/MsgConstants.h"

#define BACKLOAD 5

int* crearSocket(){
	int * sockfd = new int();
	(*sockfd) = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM = TCP
	int bla = 1;
	setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &bla, sizeof(int));
	if (*sockfd == -1) std::cerr << "error" << std::endl;
	return sockfd;
}

SocketHandler::SocketHandler
(struct sockaddr_in * addr, Lobby * lob, MyDatabase * data){
	this->db = data;
	this->lobby = lob;
	//Se crea el socket
	int * sck = crearSocket();
	this->sock_listener = sck;
	//getPort es valido solo cuando se crea, desp de acceptar una
	//conexion cambia el numero del port
	this->port = ntohs(addr->sin_port);
	this->addr = addr;
	this->keep_accepting = true;
	//bindeo, asocia sockaddr con el socket
	bind(*sock_listener, (struct sockaddr *)addr, sizeof(struct sockaddr));
}

void SocketHandler::run(){
	while (keep_accepting){
		unsigned int cli_len = sizeof(*(this->addr));
		int new_cli = accept(*sock_listener, (struct sockaddr*) this->addr, &cli_len);
		if (new_cli >= 0){
			std::cout << "Cliente Aceptado"<< std::endl;
			this->addClient(new_cli);//addClient decide si acepta o no
		}
	}
}

void SocketHandler::addClient(int & new_client){
	ClientHandler * ch = new ClientHandler(new_client);
	ClientAuthenticator ca(new_client, this->db);
	if (ca.authenticate()){
		ca.setPasswordTo(ch); //setea el password que recibio el CA al client
		this->lobby->addNewClient(ch);
	}else{
		close(new_client);
		delete ch;
	}
}

uint16_t SocketHandler::getPort(){
	return this->port;
}

void SocketHandler::stopAccepting(){
	this->keep_accepting = false;
	shutdown(*sock_listener, 2); //salta el accept() actual
	close(*sock_listener);
}

void SocketHandler::setListeningMode(){
	int r;
	r = listen(*sock_listener, BACKLOAD);
	if (r == -1) std::cerr << "Error." << std::endl;
}

SocketHandler::~SocketHandler() {
	delete addr;
	delete sock_listener;
}
