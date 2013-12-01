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

class Room;

class ClientHandler : public Thread{
	std::string passwd;
	std::string userid;
	unsigned level;

	FormattedSocket * sock;
	Room * room;
	bool keep_listening;
	void run();

public:
	explicit ClientHandler(int sock);
	void setPassword(std::string pass);
	void setUserid(std::string userid);
	std::string getUserid();
	void setRoom(Room * r);
	unsigned getLevel();
	void setLevel(unsigned l);
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
	/*
	 * exitRoom le avisa al room que este cliente desea salir.
	 */
	void exitRoom();
	virtual ~ClientHandler();
};

#endif /* CLIENTHANDLER_H_ */
