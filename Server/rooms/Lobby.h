/*
 * Lobby.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef LOBBY_H_
#define LOBBY_H_

#include <map>
#include "RoomKiller.h"
#include "../../libs/wrappers/Thread.h"

class Room;
class ClientHandler;
class MyDatabase;

class Lobby : public Thread{
	std::map<unsigned long,Room*> rooms;
	MyDatabase * db;
	RoomKiller room_killer;


	void run(void * data = NULL);

public:
	Lobby(MyDatabase * database);
	/*
	 * addClient agrega a un room el cliente indicado, haciendo uso de
	 * MatchMakingStrategy
	 */
	void addClient(ClientHandler * ch); //usar solo cuando es un cliente viejo, que
										//viene de otro room, ya que no inicia el
										//thread
	/*
	 * addNewClient agrega un nuevo cliente a un room, iniciando previamente el
	 * hilo del cliente. Cada vez que se agrega un nuevo cliente,
	 * tambien se hace una limpieza de los rooms que no estan activos.
	 */
	void addNewClient(ClientHandler * ch); //Usar solo cuando es un nuevo cliente
	/*
	 * createRoom agrega un room a la lista para el CH indicado.
	 */
	void createRoom(ClientHandler * ch);
	/*
	 * getRoom devuelve el room que tiene el id indicado, o null si no lo hay.
	 */
	Room * getRoom(unsigned long id);
	/*
	 * endMatch termina un room.
	 */
//	void endMatch(unsigned long id);
	/*
	 * endAllMatches termina las partidas del servidor.
	 */
//	void endAllMatches();
	/*
	 * getNotFullNotActiveRoom devuelve un room que no este jugando ni lleno. Si
	 * no encuentra ninguno devuelve NULL.
	 */
	Room * getNotFullNotPlayingRoom();

	virtual ~Lobby();
};

#endif /* LOBBY_H_ */
