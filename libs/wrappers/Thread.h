/*
 * Thread.h
 *
 *  Created on: 03/10/2013
 *      Author: juan
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

namespace std {

/*
 * La clase Thread contiene la funcionalidad aportada por pthread.h. Si una
 * clase desea utilizar multiples hilos, debe heredar de Thread.
 */

class Thread {
	pthread_t myThread;
public:
	Thread();
	void start();
//	void start(void * data);
	void join();
	virtual void run() = 0;
//	virtual void run(void * obj);
	virtual ~Thread();
};

} /* namespace std */
#endif /* THREAD_H_ */
