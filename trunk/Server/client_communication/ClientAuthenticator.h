/*
 * ClientAuthenticator.h
 *
 *  Created on: 23/10/2013
 *      Author: juan
 */

#ifndef CLIENTAUTHENTICATOR_H_
#define CLIENTAUTHENTICATOR_H_

#include "ClientHandler.h"
#include "../../libs/communication_protocol/FormattedSocket.h"
#include "../../libs/database/MyDatabase.h"
#include <string>

class ClientAuthenticator {
	/*
	 * clients_password es el pass que el cliente uso para autenticarse.
	 * Se utiliza para firmar sus mensajes.
	 */
	std::string clients_password;
	std::string clients_username;
	ClientHandler * client_handler;
	FormattedSocket sock;
	MyDatabase * db;
	/*
	 * login chequea los datos que envio el usuario con los de la base de datos.
	 * Devuelve si se logueo o no.
	 */
	bool login();
	/*
	 * registerUser registra un nuevo usuario en la base de datos. Devuelve true
	 * si se pudo registrar exitosamente false si no (si hay 2 users con el mismo
	 * id devuelve false).
	 */
	bool registerUser();

public:
	ClientAuthenticator(int socket, MyDatabase * data, ClientHandler* ch);
	/*
	 * authenticate recibe el modo de autenticacion que pide el usuario y decide
	 * si tiene que registrar un usuario nuevo o loguearlo.
	 */
	bool authenticate();
	/*
	 * setPasswordTo setea el password de un usuario recientemente logueado a su
	 * representacion del lado del server (ClientHandler).
	 */
	void setIdsTo(ClientHandler * ch);
	/*
	 * sendIdsVerifMsg envia el mensaje de verificacion de logueo al cliente.
	 * success indica si se logueo/registro con exito o no.
	 */
	void sendIdsVerifMsg(bool success);
	/*
	 * getIds recibe la identificacion del cliente y setea el password al
	 * ClientHandler correspondiente.
	 */
	void getIds(std::string & user, std::string & passwd);
	virtual ~ClientAuthenticator();
};

#endif /* CLIENTAUTHENTICATOR_H_ */
