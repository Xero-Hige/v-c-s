/*
 * common_HMAC.h
 *
 *  Created on: 15/10/2013
 *      Author: juan
 */

#ifndef COMMON_HMAC_H_
#define COMMON_HMAC_H_

#include <string>

/*
 * HMAC devuelve en digest los 20 bytes resultantes de aplicarle la firma
 * a 'msg' con la clave 'key'.
 */
void HMAC(std::string key, std::string msg, unsigned char * digest);

#endif /* COMMON_HMAC_H_ */
