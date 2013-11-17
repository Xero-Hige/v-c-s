/*
 * RoomKiller.h
 *
 *  Created on: 02/11/2013
 *      Author: juan
 */

#ifndef ROOMKILLER_H_
#define ROOMKILLER_H_

#include "../../libs/wrappers/Thread.h"
#include "Room.h"
#include <map>

class RoomKiller : public Thread{
	std::map<unsigned long,Room*> * rooms;
	bool keep_running;

	void run();

public:
	RoomKiller();
	void setRooms(std::map<unsigned long,Room*> * v);
	void stop();
	virtual ~RoomKiller();
};

#endif /* ROOMKILLER_H_ */
