/*
 * ThreadWithData.cpp
 *
 *  Created on: 01/12/2013
 *      Author: juan
 */

#include "ThreadWithData.h"

ThreadWithData::ThreadWithData() {
	// TODO Auto-generated constructor stub

}

struct thread_data{
	ThreadWithData * t;
	void * data;
};

void * starterWithArg(void * d){
	struct thread_data * thread_data = (struct thread_data *)d;
	thread_data->t->run(thread_data->data);
	delete thread_data;
	return NULL;
}

void ThreadWithData::start(void * d){
	struct thread_data * td = new struct thread_data();
	td->t = this;
	td->data = d;
	pthread_create(&myThread, NULL, starterWithArg, (void*) td);
}

void ThreadWithData::join(){
	pthread_join(myThread, NULL);
}

ThreadWithData::~ThreadWithData() {
	// TODO Auto-generated destructor stub
}

