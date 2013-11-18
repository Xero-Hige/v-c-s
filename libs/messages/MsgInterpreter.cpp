/*
 * MsgInterpreter.cpp
 *
 *  Created on: 03/11/2013
 *      Author: juan
 */

#include "MsgInterpreter.h"
#include <iostream>

MsgInterpreter::MsgInterpreter() {
	// TODO Auto-generated constructor stub

}

//Devuelve si se presiono el char de salida
bool MsgInterpreter::interpret(std::string s) {
	std::cout << s << std::endl;
	if (s.compare("q") == 0){
		std::cout << "Mensaje: SALIDA" << std::endl;
		return true;
	}
	else if (s.compare(CLIENT_EXIT_ROOM) == 0){
		exitRoom();
		return false;
	}
	interpretParticularMsg(s);
	return false;
}

MsgInterpreter::~MsgInterpreter() {
	// TODO Auto-generated destructor stub
}