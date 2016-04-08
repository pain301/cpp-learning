#include <iostream>

class A{
private:
	int _a;
public:
	A(int a = 0);
	~A();
	void setA(int a);
	void print();
};

A::A(int a):_a(a){
	std::cout<<"A(int)"<<std::endl;
}

A::~A(){
	std::cout<<"~A()"<<std::endl;
}

void A::setA(int a){
	_a = a;
}

void A::print(){
	std::cout<<"A::print()"<<" _a = "<<_a<<std::endl;
}

class B:virtual public A{};
class C:virtual public A{};

class D:public B,public C{};

int main(){
	D d;
	d.setA(100);
	d.print();
	//d.B::setA(10);
	//d.B::print();
	return 0;
}
