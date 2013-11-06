/*
 * BigEndianProtocol.cpp
 *
 *  Created on: 04/10/2013
 *      Author: juan
 */

#include "BigEndianProtocol.h"
#include <inttypes.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <sstream>

void insertSize(char * buf, uint32_t nro){
	//htonl convierte desde el byte-ordering de mi maquina a big endian
	uint32_t be_nro = htonl(nro);
	//Como ya tengo el nro en big-endian copio uno a uno los bytes
	char * ptr_nro = (char *)&be_nro;
	for (unsigned i = 0; i < sizeof(uint32_t); i++){
		buf[i] = ptr_nro[i];
	}
}

uint32_t readSize(const char * buf){
	uint32_t nro;
	char * ptr_nro = (char *)&nro;
	//Copio 1 a 1 los bytes
	for (unsigned i = 0; i < sizeof(uint32_t); i++){
		ptr_nro[i] = buf[i];
	}
	//Convierto desde big-endian a el byte-ordering de mi pc
	uint32_t retorno = ntohl(nro);
	return retorno;
}

/*
 * myStrcat funciona como strcat pero no empieza a concatenar en el primer \0
 * sino luego de los bytes de tamanho.
 */
void myStrcat(char * msg_con_size, const char * msg, uint32_t size){
	//Size es de msg
	insertSize(msg_con_size, size);
	for (unsigned i = sizeof(uint32_t); i < size + sizeof(uint32_t); i++){
		msg_con_size[i] = msg[i - sizeof(uint32_t)];
	}
	return;
}

void darFormato(char * msg_con_size, std::string msg){
	myStrcat(msg_con_size, msg.c_str(), msg.size());
}
