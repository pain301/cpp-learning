#include <iostream>

class A{
public:
	virtual void fun();
	virtual void fun1();
	virtual void fun2();
};

void A::fun(){
	std::cout<<"A::fun()"<<std::endl;
}

void A::fun1(){
	std::cout<<"A::fun1()"<<std::endl;
}

void A::fun2(){
	std::cout<<"A::fun2()"<<std::endl;
}

class B{
public:
	virtual void fun();
	virtual void fun1();	
	void fun2();
	void fun3();
};

void B::fun(){
	std::cout<<"B::fun()"<<std::endl;
}

void B::fun1(){
	std::cout<<"B::fun1()"<<std::endl;
}

void B::fun2(){
	std::cout<<"B::fun2()"<<std::endl;
}

void B::fun3(){
	std::cout<<"B::fun3()"<<std::endl;
}

class C:public A,public B{
public:
	virtual void fun1();
	virtual void fun2();
	void fun3();
};

void C::fun1(){
	std::cout<<"C::fun1()"<<std::endl;
}

void C::fun2(){
	std::cout<<"C::fun2()"<<std::endl;
}

void C::fun3(){
	std::cout<<"C::fun3()"<<std::endl;
}

int main(){
	C c;
	c.B::fun();
	c.fun1();
	c.fun2();
	c.fun3();	

	std::cout<<std::endl;

	A *pa = &c;
	pa->fun();
	pa->fun1();
	pa->fun2();

	std::cout<<std::endl;

	B *pb = &c;
	pb->fun();
	pb->fun1();
	pb->fun2();
	pb->fun3();

	std::cout<<std::endl;
	
	C *pc = &c;
	pc->A::fun();
	pc->fun1();
	pc->fun2();
	pc->fun3();

	return 0;	
}
