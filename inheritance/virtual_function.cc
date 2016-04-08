#include <iostream>

class Base
{
public:
	virtual int fun1(int x)
	{
		std::cout << "Base class" << std::endl;
		return 1;
	}

	virtual int fun2(double y){
		std::cout<<"Base class"<<std::endl;
		return 2;
	}
};

class Derived : public Base
{
public:
	virtual int fun1(double x)
	{
		std::cout << "Derived class" <<std::endl;
		return 1;
	}

	virtual int fun2(double y){
		std::cout<<"Derived class"<<std::endl;
		return 1;
	}
};

int main(void)
{
	Base b;
	Derived d;

	d.fun1(1);
	d.fun2(2);

	Base *p = &b;
	Base *q = &d;
	p->fun1(1);
	q->fun1(4);	
	
	std::cout<<std::endl;
	
	p->fun2(1);
	q->fun2(2);

	return 0;
}
