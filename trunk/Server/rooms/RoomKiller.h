/*
 * RoomKiller.h
 *
 *  Created on: 02/11/2013
 *      Author: juan
 */

#ifndef ROOMKILLER_H_
#define ROOMKILLER_H_

#include "../../libs/wrappers/Thread.h"
#include <map>

class Room;

class RoomKiller : public Thread{
	std::map<unsigned long,Room*> * rooms;
	/*
	 * run itera el mapa de rooms preguntandole a cada room
	 * si esta activo o no. Si no lo esta lo elimina.
	 */
	void run(void * data);

public:
	RoomKiller();
	void setRooms(std::map<unsigned long,Room*> * v);
	virtual ~RoomKiller();
};

#endif /* ROOMKILLER_H_ */
