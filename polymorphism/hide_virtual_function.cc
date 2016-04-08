#include <iostream>

class A{
public:
	virtual int fun1(int);
};

int A::fun1(int x){
	std::cout<<"A::fun1()"<<std::endl;
	return x;
}

class B:public A{
public:
	//与基类的的虚函数不是完全相同的，不构成覆盖
	virtual int fun1(double);	
};

int B::fun1(double x){
	std::cout<<"B::fun1()"<<std::endl;
	return x;
}

void test(A &a){
	a.fun1(3);
}

int main(){
	A a;
	B b;
	test(a);
	test(b);	
	return 0;
}
