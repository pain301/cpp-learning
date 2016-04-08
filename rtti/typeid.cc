#include <iostream>
#include <typeinfo>
#include <cstring>

class A{
public:
	virtual void fun(){}
};

class B:public A{
public:
	void fun(){}
};

class C{
public:
	void fun(){}
};

class D:public C{
public:
	void fun(){}
};

template<typename T>
T max(T a,T b){
	if(typeid(T)==typeid(char *)){
		char *pa = (char *)(a);
		char *pb = (char *)(b);
		return (strcmp(pa,pb)>0?a:b);
	}else{
		return a>b?a:b;
	}
}

int main(){
	std::cout<<"type int is "<<typeid(5).name()<<std::endl;
	std::cout<<"type double is "<<typeid(double).name()<<std::endl;
	std::cout<<"type 3.14 is "<<typeid(3.14).name()<<std::endl;

	A *pa = new B;
	std::cout<<"type *pa is "<<typeid(*pa).name()<<std::endl;

	C *pc = new D;
	std::cout<<"type *pc is "<<typeid(*pc).name()<<std::endl;

	std::cout<<max<int>(22,23)<<std::endl;
	std::cout<<max<char *>("hello","pain")<<std::endl;

	return 0;
}
