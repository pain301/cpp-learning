#ifndef _MUTEXLOCK_H_
#define _MUTEXLOCK_H_

#include <pthread.h>
#include "nocopyable.hh"

class MutexLock:Nocopyable{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();
	
	pthread_mutex_t* getMutex();
private:
	pthread_mutex_t mutex;	
};

#endif
