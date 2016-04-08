#include <iostream>

class A{
public:
	void print();	
};

void A::print(){
	std::cout<<"A::print()"<<std::endl;
}

class B{
public:
	void print();
};

void B::print(){
	std::cout<<"B::print()"<<std::endl;
}

class C:public A,public B{
public:
	void print();
};

void C::print(){
	B::print();
}

int main(){
	C c;
	c.print();
	c.A::print();
	c.B::print();
	return 0;
}
