/*
 * MsgInterpreter.cpp
 *
 *  Created on: 03/11/2013
 *      Author: juan
 */

#include "MsgInterpreter.h"
#include <iostream>
#include <string>

MsgInterpreter::MsgInterpreter() {
	// TODO Auto-generated constructor stub
}

//Devuelve si se presiono el char de salida
bool MsgInterpreter::interpret(std::string s) {
	if (s.compare(CLOSE_CONNECTION) == 0){
		std::cout << "Mensaje: SALIDA" << std::endl;
		closeConnection();
		return true;
	} else if (s.compare(CLIENT_EXIT_ROOM) == 0){
		exitRoom();
	} else if (s.compare(LEVEL_DATA) == 0){
		manageLevel();
	} else if (s.compare(BOARD_PRODUCTS) == 0){
	    std::cout << "Mensaje: Serializar tablero" << std::endl;
		manageBoard();
	} else if (s.compare(REPLACEMENT_PRODUCTS) == 0){
	    std::cout << "Mensaje: Serializar reemplazos" << std::endl;
		manageReplacements();
	}
	interpretParticularMsg(s);
	return false;
}

MsgInterpreter::~MsgInterpreter() {
	// TODO Auto-generated destructor stub
}
