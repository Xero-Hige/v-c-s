/*
 * Thread.cpp
 *
 *  Created on: 03/10/2013
 *      Author: juan
 */

#include "Thread.h"
#include <pthread.h>

Thread::Thread() {
	// TODO Auto-generated constructor stub
	myThread = 0;
}

void * starter(void * d){
	Thread * thread = (Thread *)d;
	thread->run();
	return NULL;
}

void Thread::start(){
	//Se pasa this porque esta clase va a ser heredada, entonces dentro de
	//starter voy a tener acceso a la clase que estoy utilizando. De este
	//modo se llama al run de la clase hija.
	pthread_create(&myThread, NULL, starter, this);
}

void Thread::join(){
	pthread_join(myThread, NULL);
}

Thread::~Thread() {
	// TODO Auto-generated destructor stub
}
