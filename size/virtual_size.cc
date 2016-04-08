#include <iostream>

//考虑对齐
class A{
public:
	virtual void fun1(){};
private:
	int _a;	
};

class B:public A{
public:
	virtual void fun1(){};
	virtual void fun2(){};
	virtual void fun3(){};
};

class C{
public:
	virtual void fun4(){};
};

class D:virtual public C{
public:
};

int main(){
	std::cout<<"size of int is "<<sizeof(int)<<std::endl;
	std::cout<<"size of int* is "<<sizeof(int*)<<std::endl;
	std::cout<<"size of A is "<<sizeof(A)<<std::endl;
	std::cout<<"size of B is "<<sizeof(B)<<std::endl;
	std::cout<<"size of C is "<<sizeof(C)<<std::endl;
	std::cout<<"size of D is "<<sizeof(D)<<std::endl;
	
	std::cout<<std::endl;

	C c;
	D d;
	std::cout<<"size of c is "<<sizeof(c)<<std::endl;
	std::cout<<"size of d is "<<sizeof(d)<<std::endl;
	return 0;
}
