/*
 * main.cpp
 *
 *  Created on: 29/09/2013
 *      Author: juan
 */


#include <iostream>
#include "server_Server.h"
#include "server_Lobby.h"
#include "../common_src/common_Thread.h"
#include <pthread.h>
#include <string>
#include <vector>

#define CHAR_DE_SALIDA 'q'
#define SEPARADOR_PORTS ','

namespace std{

/*
 * charDeSalidaApretado devuelve true si CHAR_DE_SALIDA fue presionado.
 */
bool charDeSalidaApretado(){
	if (cin.get() == CHAR_DE_SALIDA) return true; //.get es bloqueante...
	return false;
}

/*
 * getListaPuertos devuelve una lista de ints que corresponden a los puertos
 * donde el server tiene que escuchar.
 */
vector<int*> * getListaPuertos(int argc, char * argv[]){
	vector<int*> * l_ports = new vector<int*>();
	if (argc != 2) return NULL;
	string str;
	int i = 0;
	char c = (argv[1])[i];
	while (c != '\0'){
		if (c != SEPARADOR_PORTS) {
			str += c;
		} else {
			l_ports->push_back(new int(atoi(str.c_str())));
			str.clear();
		}
		i++;
		c = (argv[1])[i];
	}
	//Agrego el ultimo
	if (str.length() > 0) l_ports->push_back(new int (atoi(str.c_str())));
	return l_ports;
}


}

int main(int argc, char *argv[]){
	std::vector<int*> * list_puertos = std::getListaPuertos(argc, argv);
	if (!list_puertos) return 0;
	std::Lobby * lob = new std::Lobby();
	std::Server s;
	s.serverListen(list_puertos, lob);
	s.acceptConnections();
	while (!std::charDeSalidaApretado()){ //ignorar
	}
	s.dejarDeAceptarConex();
	if (list_puertos) delete list_puertos;
	return 0;
}

