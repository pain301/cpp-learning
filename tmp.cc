#include <iostream>

class Bar{
private:
	static Bar mem1;
	Bar *mem2;
	//Bar mem3;
};

int lookup(const int * a){
	std::cout<<"lookup(const int * a)"<<std::endl;
}

#if 0
int lookup(int * a){
	std::cout<<"lookup(int *a)"<<std::endl;
}
#endif

class A{
public:
	A(){std::cout<<"A"<<std::endl;};
	~A(){std::cout<<"~A"<<std::endl;}
};

class B:public A{
public:
	B(A &a):_a(a){std::cout<<"B"<<std::endl;}
	~B(){std::cout<<"~B"<<std::endl;}	
private:
	A _a;
};
int main(){
	A a;
	B b(a);
	return 0;
}
