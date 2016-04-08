#include <iostream>

template<typename T>
class Stack{
private:
	T *_data;
	int _top;
	int _size;	
public:
	Stack(int size = 1);
	~Stack();
	bool isFull();
	bool isEmpty();
	bool pop(T &);
	bool push(const T&);
	T top();
};

template<typename T>
Stack<T>::Stack(int size):_size(size){
	_data = new T[_size];
	_top = -1;
}

template<typename T>
Stack<T>::~Stack(){
	_top = -1;
	delete []_data;
}

template<typename T>
bool Stack<T>::isFull(){
	return _top==_size-1;
}

template<typename T>
bool Stack<T>::isEmpty(){
	return _top==-1;
}

template<typename T>
bool Stack<T>::push(const T& e){
	if(!isFull()){
		_data[++_top] = e;
		return true;
	}else{
		return false;
	}
}

template<typename T>
bool Stack<T>::pop(T& e){
	if(!isEmpty()){
		e = _data[_top--];
		return true;
	}else{
		return false;
	}
}

template<typename T>
T Stack<T>::top(){
	if(!isEmpty())
		return _data[_top];
}

int main(){
	Stack<int> s(5);
	int i = 7;
	int e;
	while(!s.isFull()){
		s.push(i*i);
		++i;
	}
	while(!s.isEmpty()){
		s.pop(e);
		std::cout<<e<<std::endl;
	}
	return 0;
}
