/*
 * BigEndianProtocol.h
 *
 *  Created on: 04/10/2013
 *      Author: juan
 */

#ifndef BIGENDIANPROTOCOL_H_
#define BIGENDIANPROTOCOL_H_

#include <inttypes.h>
#include <string>

/*
 * insertSize ubica en los primeros 4 bytes del buffer el numero indicado
 * por 'nro', en formato Big Endian.
 * Precondicion: buf tiene que ser un buffer de mas de el size de uint32_t
 */
void insertSize(char * buf, uint32_t nro);

/*
 * readSize lee los primeros 4 bytes del buffer, e inserta esos valores en
 * una variable con el byte-ordering del procesador en uso.
 */
uint32_t readSize(const char * buf);

/*
 * darFormato inserta 'msg' en el buffer 'msg_con_size', usando los primeros
 * bytes para el tamanho.
 */
void darFormato(char * msg_con_size, std::string msg);

#endif /* BIGENDIANPROTOCOL_H_ */
