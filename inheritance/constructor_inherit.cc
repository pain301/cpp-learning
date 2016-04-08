#include <iostream>

class Base{
public:
	Base();
	Base(int b);
	~Base();
private:
	int _b;
};

Base::Base(){
	std::cout<<"Base()"<<std::endl;
}

Base::Base(int b){
	std::cout<<"Base(int)"<<std::endl;
}

Base::~Base(){
	std::cout<<"~Base()"<<std::endl;
}

class Derived:public Base{
private:
	int _d;
public:
	Derived();
	Derived(int d);
	~Derived();
};

Derived::Derived(){
	std::cout<<"Derived()"<<std::endl;
}

Derived::Derived(int d){
	std::cout<<"Derived(int)"<<std::endl;
}

Derived::~Derived(){
	std::cout<<"~Derived()"<<std::endl;
}

int main(){
	Derived d;
	return 0;
}
