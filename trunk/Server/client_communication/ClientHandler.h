/*
 * ClientHandler.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef CLIENTHANDLER_H_
#define CLIENTHANDLER_H_
#include "../../libs/wrappers/Thread.h"
#include "../../libs/messages/MsgConstants.h"
#include "../../libs/communication_protocol/FormattedSocket.h"
#include <stdlib.h>
#include <string>

class Room; //Por la refs circulares...
class Lobby;

class ClientHandler : public Thread{
	std::string passwd;
	FormattedSocket * sock;
	Room * room;
	bool keep_listening;
	void run();

public:
	explicit ClientHandler(int sock);
	void setPassword(std::string pass);
	void setRoom(Room * r);
	/*
	 * sendMsg envia el mensaje 's' a traves del socket.
	 */
	void sendMsg(std::string s);
	/*
	 * recvMsg recibe un mensaje enviado por el cliente y chequea si su funcion de
	 * hash concuerda con la del mensaje recibido. Si no concuerda cierra la
	 * conexion.
	 */
	void recvMsg(std::string & s);
	void exitRoom();
	virtual ~ClientHandler();
};

#endif /* CLIENTHANDLER_H_ */
