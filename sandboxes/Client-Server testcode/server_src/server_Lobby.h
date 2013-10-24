/*
 * Lobby.h
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#ifndef LOBBY_H_
#define LOBBY_H_

#include <vector>
#include "server_Room.h"
#include "../common_src/common_Mutex.h"
#include "../common_src/common_Thread.h"

namespace std {

class Lobby{
	friend class MatchMakingStrategy;
	Mutex m;
	vector<Room*> rooms;

public:
	Lobby();
	void addClient(ClientHandler * ch);
	virtual ~Lobby();
};

} /* namespace std */
#endif /* LOBBY_H_ */
