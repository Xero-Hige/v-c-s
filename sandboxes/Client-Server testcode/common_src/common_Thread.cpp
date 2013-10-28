/*
 * Thread.cpp
 *
 *  Created on: 03/10/2013
 *      Author: juan
 */

#include "common_Thread.h"
#include <pthread.h>

namespace std {

Thread::Thread() {
	// TODO Auto-generated constructor stub
	myThread = 0;
}

void * starter(void * d){
	Thread * thread = (Thread *)d;
	thread->run();
	return NULL;
}

//struct thread_data{
//	Thread * t;
//	void * data;
//};

//void * starterWithArg(void * d){
//	struct thread_data * thread_data = (struct thread_data *)d;
//	thread_data->t->run(thread_data->data);
//	return NULL;
//}

//void Thread::start(void * d){
//	struct thread_data td;
//	td.t = this;
//	td.data = d;
//	pthread_create(&myThread, NULL, starterWithArg, (void*) &td);
//}

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
} /* namespace std */
