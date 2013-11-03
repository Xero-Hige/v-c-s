/*
 * Mutex.cpp
 *
 *  Created on: 04/10/2013
 *      Author: juan
 */

#include "Mutex.h"
#include <pthread.h>

namespace std {

Mutex::Mutex() {
	// TODO Auto-generated constructor stub
	pthread_mutex_init(&m, NULL);
}

void Mutex::lock(){
	pthread_mutex_lock(&m);
}

void Mutex::unlock(){
	pthread_mutex_unlock(&m);
}

Mutex::~Mutex() {
	// TODO Auto-generated destructor stub
	pthread_mutex_destroy(&m);
}

} /* namespace std */
