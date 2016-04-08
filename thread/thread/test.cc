#include "thread.hh"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

class WorkThread:public Thread{
public:
	void run(){
		srand(time(NULL));
		while(1){
			int x = rand()%100;	
			if(x%10==0)
				break;
			std::cout<<"x = "<<x<<std::endl;
			sleep(1);
		}
		pthread_exit(NULL);
	}
};

int main(){
	Thread *thread = new WorkThread;
	thread->start();
	thread->join();
	delete thread;
	return 0;
}
