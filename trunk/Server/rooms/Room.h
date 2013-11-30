/*
 * Room.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <vector>
#include <string>

class Lobby;
class ClientHandler;

class Room {
	unsigned limit; //max clients
	Lobby * lob;
	std::vector<ClientHandler *> clients;
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
	 * isPlaying devuelve si en el room se esta jugando.
	 */
	bool isPlaying();
	/*
	 * endMatch termina la partida y se lo notifica al lobby.
	 */
	void endMatch();
	virtual ~Room();
};

#endif /* ROOM_H_ */
