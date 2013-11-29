/*
 * MatchMakingStrategy.h
 *
 *  Created on: 24/10/2013
 *      Author: juan
 */

#ifndef MATCHMAKINGSTRATEGY_H_
#define MATCHMAKINGSTRATEGY_H_

#include "../../libs/wrappers/Thread.h"
#include <utility>

class Lobby;
class ClientHandler;
class Room;

typedef std::pair<unsigned long, Room*> map_pair;

class MatchMakingStrategy {
	/*
	 * addUserDefined agrega al usuario a un room especificado por el mismo.
	 */
	void addUserDefined(Lobby * lob, ClientHandler * ch);
	/*
	 * addDefault agrega al usuario a un room que no este lleno, o crea uno nuevo.
	 */
	void addDefault(Lobby * lob, ClientHandler * ch);

public:
	MatchMakingStrategy();
	/*
	 * addClient agrega un cliente a algun room. Recibe desde el cliente con que
	 * criterio quiere hacerlo.
	 */
	void addClient(Lobby * lob, ClientHandler * ch);
	virtual ~MatchMakingStrategy();
};

#endif /* MATCHMAKINGSTRATEGY_H_ */
