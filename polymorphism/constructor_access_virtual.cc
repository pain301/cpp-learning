#include <iostream>

class A{
public:
	A();
	virtual void fun1();
	virtual void fun2();
	~A();
};

A::A(){};
A::~A(){};

void A::fun1(){
	std::cout<<"A::fun1()"<<std::endl;
}

void A::fun2(){
	std::cout<<"A::fun2()"<<std::endl;
}

class B:public A{
public:
	B();
	//void fun1();
	void fun2();
	~B();
};

B::B(){
	fun1();
}

B::~B(){
	fun2();
}

#if 0
void B::fun1(){
	std::cout<<"B::fun1()"<<std::endl;
}
#endif

void B::fun2(){
	std::cout<<"B::fun2()"<<std::endl;
}

class C:public B{
public:
	C();
	~C();
	void fun1();
	void fun2();
};

C::C(){}
C::~C(){}

void C::fun1(){
	std::cout<<"C::fun1()"<<std::endl;
}

void C::fun2(){
	std::cout<<"C::fun2()"<<std::endl;
}

int main(){
	C c;
	return 0;
}
