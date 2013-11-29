/*
 * Room.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef ROOM_H_
#define ROOM_H_

#include "../client_communication/ClientHandler.h"
#include "Lobby.h"
#include <vector>
#include <string>

class Room {
	unsigned limit; //max clients
	Lobby * lob;
	std::vector<ClientHandler *> clients;
	bool active;
	bool currently_playing;

public:
	static unsigned long id_counter; //Generador de un id incremental
	unsigned long id; //room id

	Room(Lobby * lob, unsigned limit, unsigned long r_id = 0);
	/*
	 * addClient agrega el cliente al room.
	 */
	bool addClient(ClientHandler* ch);
	/*
	 * exitRoom saca al cliente del room.
	 */
	bool exitRoom(ClientHandler* ch);
	/*
	 * notifyClients envia el mensaje 'msg' a todos los clientes del room.
	 */
	void notifyClients(std::string msg);
	/*
	 * isFull indica si el room esta a su limite de jugadores.
	 */
	bool isFull();
	/*
	 * isActive indica si el room esta activo (independientemente si se esta
	 * jugando o no). isActive se utiliza cuando un room recien se crea, ya que el
	 * mismo no va a tener jugadores, y no va a haber nadie jugando, pero como
	 * esta activo el RoomKiller no lo va a eliminar.
	 */
	bool isActive();
	/*
	 * isPlaying devuelve si en el room se esta jugando.
	 */
	bool isPlaying();
	virtual ~Room();
};

#endif /* ROOM_H_ */
