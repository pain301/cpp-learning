#include <iostream>

class A{
private:
	int _a;
public:
	A(int a = 0);
	~A();
};

A::A(int a):_a(a){
	std::cout<<"A::A(int)"<<std::endl;
}

A::~A(){
	std::cout<<"A::~A()"<<std::endl;
}

class B{
public:
	B();
	~B();
};

B::B(){
	std::cout<<"B::B()"<<std::endl;
}

B::~B(){
	std::cout<<"B::~B()"<<std::endl;
}

class D{
public:
	D();
	~D();
};

D::D(){
	std::cout<<"D::D()"<<std::endl;
}

D::~D(){
	std::cout<<"D::~D()"<<std::endl;
}

class C:public A,public D{
private:
	int _c;
	B b;
public:
	C(int c = 0);
	~C();
};

C::C(int c):_c(c),b(){
	std::cout<<"C()"<<std::endl;
}

C::~C(){
	std::cout<<"~C()"<<std::endl;
}

int main(){
	C c;
	return 0;
}
