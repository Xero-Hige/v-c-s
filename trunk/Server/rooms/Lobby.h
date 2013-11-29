/*
 * Lobby.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef LOBBY_H_
#define LOBBY_H_

#include <map>
//#include "RoomKiller.h"

class Room;
class ClientHandler;

class Lobby{
	friend class MatchMakingStrategy;
	std::map<unsigned long,Room*> rooms;
	//RoomKiller room_killer;

public:
	Lobby();
	/*
	 * addClient agrega a un room el cliente indicado, haciendo uso de
	 * MatchMakingStrategy
	 */
	void addClient(ClientHandler * ch); //usar solo cuando es un cliente viejo, que
										//viene de otro room, ya que no inicia el
										//thread
	/*
	 * addNewClient agrega un nuevo cliente a un room, iniciando previamente el
	 * hilo del cliente.
	 */
	void addNewClient(ClientHandler * ch); //Usar solo cuando es un nuevo cliente
	/*
	 * getRoom devuelve el room que tiene el id indicado, o null si no lo hay.
	 */
	Room * getRoom(unsigned long id);
	/*
	 * getNotFullNotActiveRoom devuelve un room que no este jugando ni lleno. Si
	 * no encuentra ninguno devuelve NULL.
	 */
	Room * getNotFullNotPlayingRoom();

	virtual ~Lobby();
};

#endif /* LOBBY_H_ */
