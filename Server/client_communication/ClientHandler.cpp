/*
 * ClientHandler.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "ClientHandler.h"
#include <arpa/inet.h>
#include "../rooms/Room.h"
#include <iostream>
#include "../../libs/communication_protocol/BigEndianProtocol.h"
#include "../rooms/MatchMakingStrategy.h"
#include "ServerMsgInterpreter.h"
#include <string>
#include <iostream>

ClientHandler::ClientHandler(int s) : sock(s){
	this->keep_listening = true;
	this->room = NULL;
	this->level = 0;
	this->is_active = true;
}

void ClientHandler::run(void * data){
	while (keep_listening){
		std::string rcvd_msg;
		if (this->recvMsg(rcvd_msg) < 0) return; //error en la conexion
		ServerMsgInterpreter msg_int(this);
		if (msg_int.interpret(rcvd_msg)) keep_listening = false;
	}
	std::cout << "Termina el thread de un cliente" << std::endl;
}

void ClientHandler::exitRoom(){
	if (room) room->exitRoom(this);
}

void ClientHandler::setPassword(std::string pass){
	this->passwd = pass;
}

void ClientHandler::setUserid(std::string user){
	this->userid = user;
}

std::string ClientHandler::getUserid(){
	return userid;
}

void ClientHandler::setRoom(Room * r){
	this->room = r;
}

unsigned ClientHandler::getLevel(){
	return level;
}

void ClientHandler::setLevel(unsigned l){
	this->level = l;
}

int ClientHandler::recvMsg(std::string & s){
	int recvd_bytes;
	if (!this->sock.recvSignedMsg(s, this->passwd, recvd_bytes))
		//Si la firma no se verifica se cierra la conexion
		this->closeConnection();
	return recvd_bytes;
}

void ClientHandler::sendMsg(std::string s){
	this->sock.sendMsg(s);
}

void ClientHandler::closeConnection(){
	//Tanto del lado del server como del lado del cliente se van a mandar mensajes
	//mutuos diciendo que la conexion se va a cerrar. Por ej:
	//server manda -> CLOSE_CONNECTION y cierra
	//cliente recibe, interpreta manda -> CLOSE_CONNECTION y cierra.
	this->keep_listening = false;
	this->sock.sendMsg(CLOSE_CONNECTION);
	this->sock.socketShutdown();
	this->sock.closeConnection();
	this->is_active = false;
//	this->join();
	this->exitRoom();
}

bool ClientHandler::isActive(){
	return this->is_active;
}

void ClientHandler::sendLevelData(){
	std::string lvl = room->loadLevel();
	sendMsg(LEVEL_DATA); //Avisa que va a enviar el level.
	sendMsg(lvl);
}

void ClientHandler::sendBoardData(){
	std::string data;
	room->getSerializedBoardProducts(data);
	sendMsg(BOARD_PRODUCTS);
	sendMsg(data);
}

void ClientHandler::sendReplacementsData(){
	std::string data;
	room->getSerializedReplacementProducts(data);
	sendMsg(REPLACEMENT_PRODUCTS); //Avisa que va a enviar el level.
	sendMsg(data);
}

FormattedSocket * ClientHandler::getSocket(){
	return &sock;
}

void ClientHandler::swapMade(Position position1, Position position2) {
    room->swapMade(userid, position1, position2);
}

ClientHandler::~ClientHandler() {
	// TODO Auto-generated destructor stub
}
