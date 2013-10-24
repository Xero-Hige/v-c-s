/*
 * main.cpp
 *
 *  Created on: 29/09/2013
 *      Author: juan
 */

#include <iostream>
#include <fstream>
#include "client_Client.h"
#include <string>

#define SEPARADOR_PUERTOIP ':'

namespace std{

/*
 * obtenerIP devuelve un string con el IP ingresado por el usuario. Si hubo algun
 * error errcode toma el valor 1.
 */
string obtenerIP(int argc, char *argv[], int &errcode){
	string s;
	s.clear();
	if (argc < 2){ //No se especifico ip y puerto
		errcode = 1;
		return s;
	}
	int indice = 0;
	char c = (argv[1])[indice]; //primer nro del ip
	while (c != SEPARADOR_PUERTOIP){
		s += c;
		indice++;
		c = (argv[1])[indice];
	}
	return s;
}

/*
 * obtenerIP devuelve un int con el puerto ingresado por el usuario. Si hubo algun
 * error errcode toma el valor 1.
 */
int obtenerPort(int argc, char *argv[], int &errcode){
	if (argc < 2){ //No se especifico ip y puerto
		errcode = 1;
		return 0;
	}
	int indice = 0;
	char c = (argv[1])[indice];
	//salteo el ip
	while (c != SEPARADOR_PUERTOIP){
		indice++;
		c = (argv[1])[indice];
	}
	//salteo el separador
	indice++;
	c = (argv[1])[indice];
	string port;
	while (c != '\0'){
		port += c;
		indice++;
		c = (argv[1])[indice];
	}
	return atoi(port.c_str());
}
}

int main(int argc, char *argv[]){
	int errcode = 0;
	std::string ip = std::obtenerIP(argc, argv, errcode);
	int port = std::obtenerPort(argc, argv, errcode);
	std::Client c(ip, port);
	c.connectServer(errcode);
	if (errcode) return errcode;
	c.enterRoom();
	c.enviarMsg();
	//Si algo fallo devuelve 1 (el codigo de error)
	if (errcode) return errcode;
	c.closeConection();
	return 0;
}
