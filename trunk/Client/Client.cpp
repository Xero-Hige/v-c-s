/*
 * Client.cpp
 *
 *  Created on: 29/09/2013
 *      Author: juan
 */

#include "Client.h"
#include <iostream>
#include <stdlib.h> //atoi strtol
#include <sys/socket.h>
#include <algorithm> //reverse de string
#include <arpa/inet.h> //inet_addr, htons, server_addr
#include <cstring> //memset
#include <string>
#include <sstream>
#include "../../libs/communication_protocol/BigEndianProtocol.h"
#include "../../libs/msgs/MsgConstants.h"
#include "server_communication/ClientMsgInterpreter.h"
#include "server_communication/Authenticator.h"

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

Client::Client() {
	int sockfd = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM = TCP
	if (sockfd == -1) cerr << "creation error" << endl;
	this->sock = new Socket(sockfd);
}

void Client::communicate(){
	ClientMsgInterpreter interpreter(this);
	bool exit_char_pressed = false;
	while (!exit_char_pressed){
		char msg[80];
		cout << "Envio: " << endl;
		scanf("%s", msg);
		string s_msg(msg);
		this->sock->sendMsg(s_msg);
		exit_char_pressed = interpreter.interpret(s_msg);
	}
}

int Client::makeConnection(string ip, port){
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

void Client::connectServer
(int & errcode, string username, string passwd, string a_type){
	//Obtiene user y pass y si los quiere usar para logearse o registrarse
	Authenticator auth(this);
	if (!auth.sendIds(username, passwd, a_type))
		errcode = 2; //passwd/username incorrectos
}

void Client::useUserDefinedMatchmaking(){
	string id;
	getRoomId(id);
	sock->sendMsg(id);
}

void Client::useDefaultMatchmaking(){
	//Do nothing
}

void Client::enterRoom(){
	string mm;
	getMatchmaking(mm);
	sock->sendMsg(mm);//envia modo de matchmaking
	if (mm.compare(MM_USER_DEF) == 0){
		useUserDefinedMatchmaking();
	} else if (mm.compare(MM_DEFAULT) == 0){
		useDefaultMatchmaking();
	}
	return;
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

void Client::closeConection(){
	sock->closeConnection();
}

Client::~Client() {
	delete sock;
}

} /* namespace std */
