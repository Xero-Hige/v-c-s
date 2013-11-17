/*
 * RoomKiller.cpp
 *
 *  Created on: 02/11/2013
 *      Author: juan
 */

#include "RoomKiller.h"
#include <iostream>

RoomKiller::RoomKiller() {
	// TODO Auto-generated constructor stub
	rooms = NULL;
	keep_running = true;
}

void RoomKiller::setRooms(std::map<unsigned long,Room*> * v){
	rooms = v;
}

void RoomKiller::run() {
	std::map<unsigned long, Room*>::iterator it = rooms->begin();
	while (keep_running) {
		Room* actual_room = it->second;
		if (!(actual_room->isActive())) {
			//erase(it++) funciona porque borra y luego incrementa el iter
			rooms->erase(it++); //MAGIA
			delete actual_room;
		} else {
			it++;
		}
		//Si llega al final vuelve a empezar
		if (it == rooms->end())
			it = rooms->begin();
	}
}

void RoomKiller::stop(){
	keep_running = false;
	this->join();
}

RoomKiller::~RoomKiller() {
	// TODO Auto-generated destructor stub
}
