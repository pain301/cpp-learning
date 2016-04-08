#include <iostream>

class A{
public:
	virtual void fun1();
	virtual void fun2();
};

void A::fun1(){
	std::cout<<"A::fun1()"<<std::endl;
}

void A::fun2(){
	std::cout<<"A::fun2()"<<std::endl;
}

class B:public A{
public:
	void fun1();
};

void B::fun1(){
	std::cout<<"B::fun1()"<<std::endl;
}

class C:public B{
public:
	void fun2();
};

void C::fun2(){
	std::cout<<"C::fun2()"<<std::endl;
}

int main(){
	A *pa = new C;
	pa->fun1();
	pa->fun2();
	return 0;
}
