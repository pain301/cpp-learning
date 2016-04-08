#include <iostream>

class Resource{};

template<typename T>
class RAII{
public:
	RAII(T *);
	~RAII();
	void reset(T *);
private:
	T *res;	
	RAII(const RAII &res);
	RAII& operator=(const RAII &res);
};

template<typename T>
RAII<T>::RAII(T *p):res(p){
	std::cout<<"RAII()"<<std::endl;
}

template<typename T>
void RAII<T>::reset(T *p){
	delete res;
	res = p;
}

template<typename T>
RAII<T>::~RAII(){
	std::cout<<"~RAII()"<<std::endl;
	delete res;
}

class ResHandler{
public:
	ResHandler();
	~ResHandler();
private:
	RAII<Resource> p1;
	RAII<Resource> p2;
};

ResHandler::ResHandler():p1(new Resource()),p2(new Resource()){
	std::cout<<"ResHandler()"<<std::endl;
}

ResHandler::~ResHandler(){
	std::cout<<"~ResHandler()"<<std::endl;
}

int main(){
	ResHandler resHandler;
	return 0;	
}
