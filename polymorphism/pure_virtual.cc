#include <iostream>

class A{
public:
	virtual void fun() = 0;
};

class B:public A{
public:
	void fun();
};

void B::fun(){
	std::cout<<"B::fun()"<<std::endl;
}

class C:public B{
public:
	void fun();
};

void C::fun(){
	std::cout<<"C::fun()"<<std::endl;
}

class D:public A{};

int main(){
	//抽象类无法分配内存
	//A *pa = new A;
	//A a;
	A *pb = new B;
	A *pc = new C;
	pb->fun();
	pc->fun();
	std::cout<<"sizeof A is "<<sizeof(A)<<std::endl;
	return 0;
}
