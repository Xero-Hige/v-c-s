/*
 * main.cpp
 *
 *  Created on: 29/09/2013
 *      Author: juan
 */


#include <iostream>
#include "Server.h"
#include "rooms/Lobby.h"
#include "rooms/Room.h"
#include "../libs/wrappers/Thread.h"
#include <stdlib.h>
#include <pthread.h>
#include <string>
#include <vector>

#define CHAR_DE_SALIDA 'q'
#define SEPARADOR_PORTS ','

/*
 * charDeSalidaApretado devuelve true si CHAR_DE_SALIDA fue presionado.
 */
bool charDeSalidaApretado(){
	//.get es bloqueante...
	if (std::cin.get() == CHAR_DE_SALIDA) return true;
	return false;
}

/*
 * getListaPuertos devuelve una lista de ints que corresponden a los puertos
 * donde el server tiene que escuchar.
 */
std::vector<int> * getListaPuertos(int argc, char * argv[]){
	if (argc != 2) return NULL;
	std::vector<int> * l_ports = new std::vector<int>();
	std::string str;
	int i = 0;
	char c = (argv[1])[i];
	while (c != '\0'){
		if (c != SEPARADOR_PORTS) {
			str += c;
		} else {
			l_ports->push_back(atoi(str.c_str()));
			str.clear();
		}
		i++;
		c = (argv[1])[i];
	}
	//Agrego el ultimo
	if (str.length() > 0) l_ports->push_back(atoi(str.c_str()));
	return l_ports;
}


int main(int argc, char *argv[]){
	Room::id_counter = 0;
	std::vector<int> * list_puertos = getListaPuertos(argc, argv);
	if (!list_puertos) return 0;
	Lobby lob;
	Server s;
	s.serverListen(list_puertos, &lob);
	s.acceptConnections();
	while (!charDeSalidaApretado()){ //ignorar
	}
	s.dejarDeAceptarConex();
	delete list_puertos;

	return 0;
}

