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
	A &refer1 = a;
	A &refer2 = b;

	a.fun();
	b.fun();
	refer1.fun();
	refer2.fun();

	std::cout<<std::endl;

	A a1;
	B b1;
	refer2 = a1;
	refer1 = b1;
	
	a.fun();
	b.fun();
	refer1.fun();
	refer2.fun();
	return 0;
}
