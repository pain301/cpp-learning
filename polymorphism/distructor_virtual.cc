#include <iostream>

class A{
private:
	char *pa;
public:
	A();
	virtual ~A();
};

A::A(){
	pa = new char[100];
	std::cout<<"A::A()"<<std::endl;
}

A::~A(){
	delete pa;
	std::cout<<"A::~A()"<<std::endl;
}

class B:public A{
private:
	char *pb;
public:
	B();
	~B();
};

B::B(){
	pb = new char[100];
	std::cout<<"B::B()"<<std::endl;
}

B::~B(){
	delete pb;
	std::cout<<"B::~B"<<std::endl;
}

int main(){
	A *a = new B();
	delete a;
	return 0;
}
