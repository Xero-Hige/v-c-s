/*
 * Room.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef ROOM_H_
#define ROOM_H_

#include "../game_manager/game_manager.h"

#include <vector>
#include <string>

class Lobby;
class ClientHandler;

class Room {
	unsigned level;
	unsigned limit; //max clients
	Lobby * lob;
	std::vector<ClientHandler *> clients;
	std::vector<std::string> usernames;
	bool currently_playing;
	bool active;
	LevelReader level_reader;
	GameManager game_manager;
	std::string getLevelName();
	void eraseUsername(std::string username);

public:
	static unsigned long id_counter; //Generador de un id incremental
	unsigned long id; //room id

	Room(Lobby * lob, unsigned limit, unsigned level,unsigned long r_id = 0);
	/*
	 * addClient agrega el cliente al room.
	 */
	bool addClient(ClientHandler* ch);
	/*
	 * exitRoom saca al cliente del room.
	 */
	bool exitRoom(ClientHandler* ch);
	/*
	 * updateActive se fija si quedan clientes jugando, de no ser asi setea el
	 * room como inactivo
	 */
	void updateActive();
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
	/* Notifica al game manager que un cliente hizo un swap */
	void swapMade(std::string user_id, Position position1, Position position2);
	/* Serializa los productos del tablero de juego en formato Json y lo *
	 * guarda en el string.                                              */
	void getSerializedBoardProducts(std::string& serialized_products);
	/*
	 * endMatch termina la partida y se lo notifica al lobby.
	 */
	void endMatch();
	/*
	 * loadLevel devuelve un string con los datos del nivel.
	 */
	std::string loadLevel();
	/*
	 * isActive devuelve si un room esta activo o no. Es la variable que determina
	 * si un room se debe eliminar o no.
	 */
	bool isActive();
	virtual ~Room();
};

#endif /* ROOM_H_ */
