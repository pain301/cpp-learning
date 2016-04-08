#ifndef _BUFFER_H_
#define _BUFFER_H_

#include "condition.hh"
#include "mutexlock.hh"
#include <queue> 

class Buffer{
private:
	MutexLock _mutex;
	std::queue<int> _que;
	Condition _full;
	Condition _empty;
	int _size;
public:
	Buffer(int size = 10);
	~Buffer();
	
	void push(int );
	int pop();
	
	bool isFull();
	bool isEmpty();	
};

#endif
