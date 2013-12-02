/*
 * RoomKiller.cpp
 *
 *  Created on: 02/11/2013
 *      Author: juan
 */

#include "RoomKiller.h"
#include "Room.h"
#include <iostream>
#include <map>

RoomKiller::RoomKiller() {
	// TODO Auto-generated constructor stub
	rooms = NULL;
}

void RoomKiller::setRooms(std::map<unsigned long,Room*> * v){
	rooms = v;
}

void RoomKiller::run(void * data) {
	for (std::map<unsigned long, Room*>::iterator it = rooms->begin();it != rooms->end(); ){
		Room* actual_room = it->second;
		if (!(actual_room->isActive())) {
			//erase(it++) funciona porque borra y luego incrementa el iter
			rooms->erase(it++); //MAGIA
			delete actual_room;
		} else {
			it++;
		}
	}
}

RoomKiller::~RoomKiller() {
	// TODO Auto-generated destructor stub
}
