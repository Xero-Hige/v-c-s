/*
 * ThreadWithData.h
 *
 *  Created on: 01/12/2013
 *      Author: juan
 */

#ifndef THREADWITHDATA_H_
#define THREADWITHDATA_H_

#include <pthread.h>

/*
 * Clase muy similar a thread solo que permite pasarle un puntero a un dato para
 * utilizar en la funcion run().
 */
class ThreadWithData {
	pthread_t myThread;

public:
	ThreadWithData();
	void start(void * data);
	void join();
	virtual void run(void * obj) = 0;
	virtual ~ThreadWithData();
};

#endif /* THREADWITHDATA_H_ */
