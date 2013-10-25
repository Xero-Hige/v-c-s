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
#include "../common_src/common_Thread.h"

namespace std {

class MatchMakingStrategy {
	Lobby * lob;
	ClientHandler * ch;
	void addUserDefined(Lobby * lob, ClientHandler * ch);
	void addDefault(Lobby * lob, ClientHandler * ch);

public:
	MatchMakingStrategy(Lobby * lob, ClientHandler * ch);
	void addClient();
	virtual ~MatchMakingStrategy();
};

} /* namespace std */
#endif /* MATCHMAKINGSTRATEGY_H_ */
