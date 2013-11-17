/*
 * Mutex.h
 *
 *  Created on: 04/10/2013
 *      Author: juan
 */

#ifndef MUTEX_H_
#define MUTEX_H_

#include <pthread.h>

/*
 * La clase Mutex encapsula los metodos de pthread_mutex, utilizados para que solo
 * un hilo pueda acceder a una porcion de codigo por vez. Si una clase quiere
 * usar esta propiedad debe contener un Mutex.
 */

class Mutex {
	pthread_mutex_t m;
public:
	Mutex();
	void lock();
	void unlock();
	virtual ~Mutex();
};

#endif /* MUTEX_H_ */
