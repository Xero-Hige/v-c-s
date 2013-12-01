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

struct thread_data{
	Thread * t;
	void * data;
};

void * starterWithArg(void * d){
	struct thread_data * thread_data = (struct thread_data *)d;
	thread_data->t->run(thread_data->data);
	delete thread_data;
	return NULL;
}

void Thread::start(void * data, int thread_type){
	//Se pasa this porque esta clase va a ser heredada, entonces dentro de
	//starter voy a tener acceso a la clase que estoy utilizando. De este
	//modo se llama al run de la clase hija.
	pthread_attr_t * attr_ptr = NULL;
	pthread_attr_t attr;
	if (thread_type == DETACHED){
		attr_ptr = &attr;
		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	}
	if (!data){
		pthread_create(&myThread, attr_ptr, starter, this);
	}else{
		struct thread_data * td = new struct thread_data();
		td->t = this;
		td->data = data;
		pthread_create(&myThread, attr_ptr, starterWithArg, (void*) td);
	}
	if (attr_ptr)pthread_attr_destroy(attr_ptr);
}

void Thread::join(){
	pthread_join(myThread, NULL);
}

Thread::~Thread() {
	// TODO Auto-generated destructor stub
}
