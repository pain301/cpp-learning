#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>

class Thread{
public:
	Thread();
	~Thread();
	void start();
	void join();
	virtual void run() = 0;
	static void* start_routine(void *arg); 
private:
	pthread_t thread_id;
	bool isRunning;
};
 
#endif
