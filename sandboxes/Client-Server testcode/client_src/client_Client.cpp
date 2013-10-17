/*
 * Client.cpp
 *
 *  Created on: 29/09/2013
 *      Author: juan
 */

#include "client_Client.h"
#include <iostream>
#include <stdlib.h> //atoi strtol
#include <sys/socket.h>
#include <algorithm> //reverse de string
#include <arpa/inet.h> //inet_addr, htons, server_addr
#include <cstring> //memset
#include <unistd.h> //close
#include <string>
#include <sstream>
#include <streambuf>
#include "../common_src/common_BigEndianProtocol.h"

namespace std {

struct sockaddr_in server_addr;

/*
 * setServerAddr configura una estructura sockaddr_in para poder utilizar el
 * puerto deseado.
 */
int setServerAddr(struct sockaddr_in & server_addr, string ip, int port){
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	//server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (inet_pton(AF_INET, ip.c_str(), &(server_addr.sin_addr)) <= 0){// IPv4
		cerr << "error inet_pton\n";
		return -1;
	}
	//memset deja a la cantidad de bytes indicada en el tercer parametro
	//a los que apunta el primer parametro
	//en el valor del segundo parametro
	return 0;
}

Client::Client(string ip, int port) {
	// TODO Auto-generated constructor stub
	sockfd = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM = TCP
	if (sockfd == -1) cerr << "creation error" << endl;
	this->ip = ip;
	this->port = port;
}

void Client::connectServer(int & errcode){
	int r;
	struct sockaddr_in s_addr;
	r = setServerAddr(s_addr, ip, port);
	//Intenta conectarse
	if (r < 0){
		//Cambia el codigo de error para que coincida con lo pedido en el informe
		errcode = 1;
		//Usa return porque si fallo setServerAddr connect se bloquea
		return;
	}
	r += connect(sockfd, (struct sockaddr*) & s_addr, sizeof(struct sockaddr));
	memset(&(server_addr.sin_zero), 0, sizeof(s_addr.sin_zero));
	//Cambia el codigo de error para que coincida con lo pedido en el informe
	if (r < 0) errcode = 1;
}

int Client::clientSend(char * buf, size_t length){
	unsigned bytes_enviados = 0;
	while (bytes_enviados == 0){
		bytes_enviados = send(sockfd, buf, length, 0);
	}
	return bytes_enviados;
}

int Client::clientReceive(char * buf, size_t length){
	return recv(sockfd, buf, length, 0);
}

void Client::closeConection(){
	close(sockfd);
}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
