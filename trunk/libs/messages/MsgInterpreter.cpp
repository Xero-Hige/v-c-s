/*
 * MsgInterpreter.cpp
 *
 *  Created on: 03/11/2013
 *      Author: juan
 */

#include "MsgInterpreter.h"
#include <iostream>

namespace std {

MsgInterpreter::MsgInterpreter() {
	// TODO Auto-generated constructor stub

}

//Devuelve si se presiono el char de salida
bool MsgInterpreter::interpret(string s) {
	cout << s << endl;
	if (s.compare("q") == 0){
		cout << "Mensaje: SALIDA" << endl;
		return true;
	}
	else if (s.compare(CLIENT_EXIT_ROOM) == 0){
		exitRoom();
		return false;
	}
	return false;
}

MsgInterpreter::~MsgInterpreter() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
