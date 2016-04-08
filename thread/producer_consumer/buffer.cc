#include "buffer.hh"

Buffer::Buffer(int size):
	_size(size),
	_mutex(),
	_full(_mutex),
	_empty(_mutex){

}

Buffer::~Buffer(){

}

void Buffer::push(int x){
	_mutex.lock();
	while(isFull()){
		_empty.wait();
	}
	_que.push(x);
	++_size;
	_mutex.unlock();
	_full.notify();
}

int Buffer::pop(){
	_mutex.lock();
	while(isEmpty()){
		_full.wait();
	}
	int tmp = _que.front();
	_que.pop();
	--_size;
	_mutex.unlock();
	_empty.notify();	
	return tmp;
}

bool Buffer::isFull(){
	return (_size==_que.size());	
}

bool Buffer::isEmpty(){
	return	(_que.size()==0); 
}
