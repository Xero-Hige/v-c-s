/*
 * Authenticator.h
 *
 *  Created on: 21/10/2013
 *      Author: juan
 */

#ifndef AUTHENTICATOR_H_
#define AUTHENTICATOR_H_

#include "../../libs/communication_protocol/FormattedSocket.h"

#include <string>

class Authenticator {
	/*
	 * sock es el socket que se comunica con el servidor.
	 */
	FormattedSocket * sock;
	/*
	 * receiveAuthVerif indica si la verificacion que envia el servidor por el log
	 * in es la esperada o no. Si devuelve true significa que el logueo/registro
	 * se realizo con exito.
	 */
	bool receiveAuthVerif();

public:
	Authenticator();
	void setSocket(FormattedSocket * s);
	/*
	 * authenticate recibe usuario password y tipo (login/registro) de autenticacion
	 * que se quiere realizar. Devuelve si se realizo con exito o no.
	 */
	bool authenticate(std::string u, std::string passwd, std::string type);
	virtual ~Authenticator();
};

#endif /* AUTHENTICATOR_H_ */
