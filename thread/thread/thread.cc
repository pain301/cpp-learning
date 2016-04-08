#include "thread.hh"
#include <iostream>

Thread::Thread():thread_id(0),isRunning(false){
	std::cout<<"Thread()"<<std::endl;	
}

Thread::~Thread(){
	std::cout<<"~Thread()"<<std::endl;
	if(isRunning){
		pthread_detach(thread_id);
		isRunning = false;
	}
}

void Thread::start(){
	pthread_create(&thread_id,NULL,start_routine,this);	
	isRunning = true;
}

void Thread::join(){
	pthread_join(thread_id,NULL);
	isRunning = false;
}

void* Thread::start_routine(void* arg){
	Thread* pThread = static_cast<Thread*>(arg);
	pThread->run();
	return NULL;
}
