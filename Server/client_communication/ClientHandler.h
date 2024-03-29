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
#include "../../libs/position/position.h"

#include <stdlib.h>
#include <string>

class Room;

class ClientHandler : public Thread{
	std::string passwd;
	std::string userid;
	unsigned level;

	FormattedSocket sock;
	Room * room;
	bool keep_listening;
	bool is_active;
	void run(void * data = NULL);

public:
	explicit ClientHandler(int sock);
	void setPassword(std::string pass);
	void setUserid(std::string userid);
	std::string getUserid();
	void setRoom(Room * r);
	FormattedSocket * getSocket();
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
	int recvMsg(std::string & s);

	/* Le notifica al room que el cliente hizo un swap */
	void swapMade(Position position1, Position position2);

	/*
	 * exitRoom le avisa al room que este cliente desea salir.
	 */
	void exitRoom();
	/*
	 * closeConnection cierra la conexion del socket y le avisa al cliente que el
	 * servidor esta cerrando la conexion. Se borra el cliente del server.
	 */
	void closeConnection();
	/*
	 * sendLevelData envia al cliente los datos del nivel.
	 */
	void sendLevelData();
	/*
	 * sendBoardData envia al cliente los datos del tablero.
	 */
	void sendBoardData();
	/*
	 * sendReplacementsData envia al cliente los datos de los reemplazos.
	 */
	void sendReplacementsData();
	/*
	 * isActive pregunta al cliente si esta activo, es decir, si el cliente todavia
	 * esta conectado.
	 */
	bool isActive();
	virtual ~ClientHandler();
};

#endif /* CLIENTHANDLER_H_ */
