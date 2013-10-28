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
#include <string>
#include <sstream>
#include "../common_src/common_BigEndianProtocol.h"
#include "../common_src/common_MsgConstants.h"
#include "client_Authenticator.h"
#include "client_MsgInterpreter.h"

#include <stdio.h>

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
	int sockfd = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM = TCP
	if (sockfd == -1) cerr << "creation error" << endl;
	s_handler = new ServerHandler(sockfd);
	this->ip = ip;
	this->port = port;
}

void Client::communicate(){
	MsgInterpreter interpreter(this);
	bool exit_char_pressed = false;
	while (!exit_char_pressed){
		char msg[80];
		cout << "Envio: " << endl;
		scanf("%s", msg);
		string s_msg(msg);
		this->s_handler->sendMsg(s_msg);
		exit_char_pressed = interpreter.interpret(s_msg);
//		s_msg.clear();
//		this->s_handler->recvMsg(s_msg);
//		cout << "Recibido: ";
//		cout << s_msg << endl;
	}
}

int Client::makeConnection(){
	int r;
	struct sockaddr_in s_addr;
	r = setServerAddr(s_addr, ip, port);
	//Intenta conectarse
	if (r < 0)
		return 1;
	int sock = s_handler->getSocket();
	r += connect(sock, (struct sockaddr*) & s_addr, sizeof(struct sockaddr));
	memset(&(server_addr.sin_zero), 0, sizeof(s_addr.sin_zero));
	if (r < 0) return 1;
	return 0;
}

void Client::connectServer(int & errcode){
	//Obtiene user y pass y si los quiere usar para logearse o registrarse
	string a_type, username, passwd;
	getConnectionType(a_type);
	getUsername(username);
	getPasswd(passwd);
	errcode = makeConnection(); //1 si no se pudo establecer conexion
	Authenticator auth(this);
	if (!auth.sendIds(username, passwd, a_type))
		errcode = 2; //passwd/username incorrectos
}

void Client::useUserDefinedMatchmaking(){
	string id;
	getRoomId(id);
	s_handler->sendMsg(id);
}

void Client::useDefaultMatchmaking(){
	//Do nothing
}

void Client::enterRoom(){
	string mm;
	getMatchmaking(mm);
	s_handler->sendMsg(mm);//envia modo de matchmaking
	if (mm.compare(MM_USER_DEF) == 0){
		useUserDefinedMatchmaking();
	} else if (mm.compare(MM_DEFAULT) == 0){
		useDefaultMatchmaking();
	}
	return;
}

int Client::sendMsg(string msg){
	return this->s_handler->sendMsg(msg);
}

int Client::recvMsg(string msg){
	return this->s_handler->recvMsg(msg);
}

void Client::getRoomId(string & id){
	cout << "Enter room id: \n";
	char c[256];
	scanf("%s", c);
	id.append(c);
	return;
}

void Client::getMatchmaking(string & mm){
	cout << "1 - User-defined room \n2 - Default\n";
	char c[256];
	scanf("%s", c);
	mm.append(c);
	return;
}

void Client::getConnectionType(string & a_type){
	cout << "1 - Login \n2 - Registrarse\n";
	char c[256];
	scanf("%s", c);
	a_type.append(c);
	return;
}

void Client::getPasswd(string & passwd){
	cout << "Ingresar passwd: " << endl;
	char c[256];
	scanf("%s", c);
	passwd.append(c);
}
void Client::getUsername(string & user){
	cout << "Ingresar username: " << endl;
	char c[256];
	scanf("%s", c);
	user.append(c);
}

void Client::closeConection(){
	s_handler->closeConnection();
}

Client::~Client() {
	delete s_handler;
}

} /* namespace std */
