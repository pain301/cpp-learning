#ifndef _CONDITION_H_
#define _CONDITION_H_

#include <pthread.h>
#include "nocopyable.hh"

class MutexLock;

class Condition:public Nocopyable{
private:
	pthread_cond_t _cond;
	MutexLock &_mutex;
public:
	Condition(MutexLock &);
	~Condition();

	void wait();
	void notify();
	void notifyAll();
};

#endif
