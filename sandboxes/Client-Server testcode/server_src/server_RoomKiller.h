/*
 * RoomKiller.h
 *
 *  Created on: 02/11/2013
 *      Author: juan
 */

#ifndef ROOMKILLER_H_
#define ROOMKILLER_H_

#include "../common_src/common_Thread.h"
#include "server_Room.h"
#include <map>

namespace std {

class RoomKiller : public Thread{
	map<unsigned long,Room*> * rooms;
	bool keep_running;

	void run();

public:
	RoomKiller();
	void setRooms(map<unsigned long,Room*> * v);
	void stop();
	virtual ~RoomKiller();
};

} /* namespace std */
#endif /* ROOMKILLER_H_ */
