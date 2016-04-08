#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>
#include "buffer.hh"

class Thread{
private:
	pthread_t thread_id;
	bool isRunning;
public:
	Thread();
	~Thread();
	void start();
	void join();
	virtual void run() = 0;
	
	static void* start_routine(void *arg);
};

class ProducerThread:public Thread{
private:
	Buffer &_buffer;
public:
	ProducerThread(Buffer &);
	void run();
};

class ConsumerThread:public Thread{
private:
	Buffer &_buffer;
public:
	ConsumerThread(Buffer &);
	void run();
};

#endif
