/*
 * MatchMakingStrategy.h
 *
 *  Created on: 24/10/2013
 *      Author: juan
 */

#ifndef MATCHMAKINGSTRATEGY_H_
#define MATCHMAKINGSTRATEGY_H_

#include "server_ClientHandler.h"
#include "server_Lobby.h"

namespace std {

class MatchMakingStrategy {
public:
	MatchMakingStrategy();
	void addClient(Lobby * lob, ClientHandler * ch);
	void addUserDefined(Lobby * lob, ClientHandler * ch);
	void addDefault(Lobby * lob, ClientHandler * ch);
	virtual ~MatchMakingStrategy();
};

} /* namespace std */
#endif /* MATCHMAKINGSTRATEGY_H_ */
