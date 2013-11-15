/*
 * Client.cpp
 *
 *  Created on: 29/09/2013
 *      Author: juan
 */

#include "server_connector.h"

#include <arpa/inet.h> //inet_addr, htons, server_addr
#include <bits/socket_type.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <algorithm> //reverse de string
#include <cstring> //memset
#include <iostream>
#include <sstream>
#include <string>

#include "../../libs/communication_protocol/BigEndianProtocol.h"
#include "../../libs/messages/MsgConstants.h"
#include "../server_communication/Authenticator.h"
#include "../server_communication/ClientMsgInterpreter.h"


using std::cerr;
using std::endl;

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

Server_Connector::Server_Connector() {
	int sockfd = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM = TCP
	if (sockfd == -1) cerr << "creation error" << endl;
	this->sock = new Socket(sockfd);
	this->exit_char_pressed = false;
}

void Server_Connector::communicate(){
	while (!exit_char_pressed){
		char msg[80];
		cout << "Envio: " << endl;
		scanf("%s", msg);
		string s_msg(msg);
		this->sock->sendMsg(s_msg);
	}
}

int Server_Connector::makeConnection(string ip, int port){
	int r;
	struct sockaddr_in s_addr;
	r = setServerAddr(s_addr, ip, port);
	//Intenta conectarse
	if (r < 0)
		return 1;
	int actual_sock = this->sock->getSocket();
	r += connect(actual_sock, (struct sockaddr*) & s_addr, sizeof(struct sockaddr));
	memset(&(server_addr.sin_zero), 0, sizeof(s_addr.sin_zero));
	if (r < 0) return 1;
	return 0;
}

void Server_Connector::connectServer
(string username, string passwd, string a_type){
	//Obtiene user y pass y si los quiere usar para logearse o registrarse
	auth.authenticate(this, username, passwd, a_type);
}

void Server_Connector::useUserDefinedMatchmaking(){
	string id;
	getRoomId(id);
	sock->sendMsg(id);
}

void Server_Connector::useDefaultMatchmaking(){
	//Do nothing
}

void Server_Connector::enterRoom(){
	string mm;
	getMatchmaking(mm);
	sock->sendMsg(mm);//envia modo de matchmaking
	int i_mm = atoi (mm.c_str());
	if (i_mm == MM_USER_DEF){
		useUserDefinedMatchmaking();
	} else if (i_mm == MM_DEFAULT){
		useDefaultMatchmaking();
	}
	return;
}

void Server_Connector::exitCharPressed(){
	exit_char_pressed = true;
}

void Server_Connector::getRoomId(string & id){
	cout << "Enter room id: \n";
	char c[256];
	scanf("%s", c);
	id.append(c);
	return;
}

void Server_Connector::getMatchmaking(string & mm){
	cout << "1 - User-defined room \n2 - Default\n";
	char c[256];
	scanf("%s", c);
	mm.append(c);
	return;
}

void Server_Connector::closeConection(){
	sock->closeConnection();
}

Server_Connector::~Server_Connector() {
	delete sock;

} /* namespace std */
