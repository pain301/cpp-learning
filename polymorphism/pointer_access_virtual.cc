#include <iostream>

class A{
public:
	virtual void fun();
};

void A::fun(){
	std::cout<<"A::fun()"<<std::endl;
}

class B:public A{
public:
	B(int val = 10);
	void fun();
	void print();
private:
	int _val;
};

B::B(int val):_val(val){

}

void B::fun(){
	std::cout<<"B::fun()"<<std::endl;
}

void B::print(){
	std::cout<<"B::print() _val =  "<<_val<<std::endl;
}

class C:public A{
public:
	void fun();
};

void C::fun(){
	std::cout<<"C::fun()"<<std::endl;
}

void test(A *p){
	p->fun();
}

int main(){
	A a;
	B b;
	C c;

	//指针访问
	test(&a);
	test(&b);
	test(&c);

	//对象名访问
	a.fun();
	b.fun();
	c.fun();

	//此时仍然访问基类的虚函数
	a = b;
	a.fun();

	std::cout<<std::endl;
	
	A *pa = &a;
	B *pb = &b;
	pa->fun();
	pb->fun();
	std::cout<<std::endl;

	pa = &b;
	pb = (B *)&a;

	//只与指针的指向内容相关
	pa->fun();
	pb->fun();	
	
	//派生指针指向基类对象，并且访问基类不存在的数据，为垃圾值
	pb->print();

	return 0;
}
