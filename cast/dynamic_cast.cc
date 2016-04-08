#include <iostream>

class A{
public:
	virtual void fun();
	void funA();
};

void A::fun(){
	std::cout<<"A::fun()"<<std::endl;
}

void A::funA(){
	std::cout<<"A::funA()"<<std::endl;
}

class B:public A{
public:
	void fun();
	void funB();	
};

void B::fun(){
	std::cout<<"B::fun()"<<std::endl;
}

void B::funB(){
	int i = 3;
	std::cout<<"B::funB()"<<std::endl;
	std::cout<<"i = "<<i<<std::endl;
}

int main(){
	
	A *pa = new B;
	B *pb = (B *)pa;
	pb->fun();
	pb->funA();
	pb->funB();

	std::cout<<std::endl;
	
	pa = new A;
	pb = dynamic_cast<B*>(pa);
	if(pb==NULL)
		return 0;
	pb->fun();
	pb->funA();
	pb->funB();
	return 0;
}
