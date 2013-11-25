/*
 * common_HMAC.h
 *
 *  Created on: 15/10/2013
 *      Author: juan
 */

#ifndef COMMON_HMAC_H_
#define COMMON_HMAC_H_

#include <string>

#define SHA_DIGEST_SIZE 20 //160bits

/*
 * HMAC devuelve en digest los SHA_DIGEST_SIZE bytes resultantes de aplicarle
 * la firma a 'msg' con la clave 'key'.
 */
void HMAC(std::string key, std::string msg, unsigned char * digest);

/*
 * HMACSignedMsg hace lo mismo que HMAC pero lo apendea al msg.
 */
void HMACSignedMsg(std::string & msg, std::string key);

/*
 * checkSignedMsg verifica si el hash digest al final de 'signed_msg' es correcto.
 */
bool checkSignedMsg(std::string signed_msg, std::string key);

#endif /* COMMON_HMAC_H_ */
