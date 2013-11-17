/*
 * MatchMakingStrategy.h
 *
 *  Created on: 24/10/2013
 *      Author: juan
 */

#ifndef MATCHMAKINGSTRATEGY_H_
#define MATCHMAKINGSTRATEGY_H_

#include "../client_communication/ClientHandler.h"
#include "Lobby.h"
#include "../../libs/wrappers/Thread.h"

typedef std::pair<unsigned long, Room*> map_pair;

class MatchMakingStrategy {
	void addUserDefined(Lobby * lob, ClientHandler * ch);
	void addDefault(Lobby * lob, ClientHandler * ch);

public:
	MatchMakingStrategy();
	void addClient(Lobby * lob, ClientHandler * ch);
	virtual ~MatchMakingStrategy();
};

#endif /* MATCHMAKINGSTRATEGY_H_ */
