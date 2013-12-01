/*
 * Thread.h
 *
 *  Created on: 03/10/2013
 *      Author: juan
 */

#ifndef THREAD_H_
#define THREAD_H_

#define JOINABLE 0
#define DETACHED 1

#include <pthread.h>

/*
 * La clase Thread contiene la funcionalidad aportada por pthread.h. Si una
 * clase desea utilizar multiples hilos, debe heredar de Thread.
 */

class Thread {
	pthread_t myThread;

public:
	Thread();
	void start(void * data = NULL, int thread_type = JOINABLE);
	void join();
	virtual void run(void * data = NULL) = 0;
	virtual ~Thread();
};

#endif /* THREAD_H_ */
