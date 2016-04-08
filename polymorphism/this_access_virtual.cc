#include <iostream>

class A{
public:
	virtual void fun();
	void call_fun1();
	void call_fun2();
};

void A::fun(){
	std::cout<<"A::fun()"<<std::endl;
}

void A::call_fun1(){
	std::cout<<"A::call_fun1()"<<std::endl;
	this->fun();
}

void A::call_fun2(){
	std::cout<<"A::call_fun2()"<<std::endl;
	//不加A::相当于this->fun()，在派生类中产生虚函数特性
	A::fun();
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
	
	a.call_fun1();
	a.call_fun2();
	b.call_fun1();
	b.call_fun2();
	std::cout<<std::endl;

	A *pa = &a;
	pa->call_fun1();
	pa->call_fun2();

	pa = &b;
	//基类指针在成员函数内部调用虚函数
	pa->call_fun1();	
	pa->call_fun2();
	return 0;
}
