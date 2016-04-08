#include <iostream>

class A{
public:
	virtual void fun();
};

void A::fun(){
	std::cout<<"A::fun()"<<std::endl;
}

class B:public A{
public:
	void fun();
};

void B::fun(){
	std::cout<<"B::fun()"<<std::endl;
}

int main(){
	A a;
	B b;
	
	A *pa = &a;
	B *pb = &b;
	pa->fun();
	pb->fun();
	
	std::cout<<std::endl;	

	pa = pb;	
	pb = (B *)&a;
	pa->fun();
	pb->fun();
	pb->A::fun();
		
	std::cout<<std::endl;
	return 0;
}
