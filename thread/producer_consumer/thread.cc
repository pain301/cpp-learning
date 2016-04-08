#include "thread.hh"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Thread::Thread():thread_id(0),isRunning(false){

}

Thread::~Thread(){
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

void* Thread::start_routine(void *arg){
	Thread* pThread = static_cast<Thread *>(arg);
	pThread->run();
	return NULL;
}

ProducerThread::ProducerThread(Buffer &buffer):_buffer(buffer){

}

void ProducerThread::run(){
	srand(time(NULL));
	while(1){
		int tmp = rand()%100;
		_buffer.push(tmp);
		std::cout<<"produce num = "<<tmp<<std::endl;
		sleep(2);
	}
}

ConsumerThread::ConsumerThread(Buffer &buffer):_buffer(buffer){

}

void ConsumerThread::run(){
	while(1){
		int tmp = _buffer.pop();
		std::cout<<"consume num = "<<tmp<<std::endl;
		sleep(1);
	}
}
