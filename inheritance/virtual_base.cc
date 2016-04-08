#include <iostream>

class A{
private:
	int _a;
public:
	A(int a = 0);
	~A();
	void print();	
};

A::A(int a):_a(a){
	std::cout<<"A::A(int a)"<<std::endl;
}

A::~A(){
	std::cout<<"A::~A()"<<std::endl;
}

void A::print(){
	std::cout<<"_a = "<<_a<<std::endl;
}

class B:virtual public A{
public:
	B(int a = 0);
	~B();
};

B::B(int a):A(a){
	std::cout<<"B::B()"<<std::endl;
}

B::~B(){
	std::cout<<"B::~B()"<<std::endl;
}

class C:virtual public A{
public:
	C(int a = 0);
	~C();
};

C::C(int a):A(a){
	std::cout<<"C::C()"<<std::endl;
}

C::~C(){
	std::cout<<"C::~C()"<<std::endl;
}

class D:public B,public C{
public:
	D(int a = 0);
	~D();
};

D::D(int a):B(a),C(a),A(a){
	std::cout<<"D::D()"<<std::endl;
}

D::~D(){
	std::cout<<"D::~D()"<<std::endl;
}

int main(){
	D d(10);
	d.print();
	return 0;
}
