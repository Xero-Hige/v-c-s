/*
 * Lobby.cpp
 *
 *  Created on: 18/10/2013
 *      Author: juan
 */

#include "server_Lobby.h"
#include "server_Room.h"
#include "server_MatchMakingStrategy.h"

namespace std {

Lobby::Lobby() {
	// TODO Auto-generated constructor stub

}

void Lobby::addClient(ClientHandler * ch) {
	MatchMakingStrategy mms;
	mms.addClient(this, ch);
}

Lobby::~Lobby() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
