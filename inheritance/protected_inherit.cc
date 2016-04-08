#include <iostream>

class Base{
private:
	int _a;
protected:
	int _b;
public:
	int _c;
	Base(int a = 0,int b = 0,int c = 0);
	~Base();
	void display();
	int getA();
	int getB();
	int getC();
};

Base::Base(int a,int b,int c):_a(a),_b(b),_c(c){
	std::cout<<"Base(int a,int b,int c)"<<std::endl;
}

Base::~Base(){
	std::cout<<"~Base()"<<std::endl;
}

void Base::display(){
	std::cout<<"_a = "<<_a<<",_b = "<<_b<<",_c = "<<_c<<std::endl;
}

int Base::getA(){
	return _a;
}

int Base::getB(){
	return _b;
}

int Base::getC(){
	return _c;
}

class Drived:protected Base{
private:
	int _d;
public:
	Drived(int a = 0,int b = 0,int c = 0,int d = 0);
	~Drived();
	void display();
	int getD();
};

Drived::Drived(int a,int b,int c,int d):Base(a,b,c),_d(d){
	std::cout<<"Drived(int a,int b,int c,int d)"<<std::endl;	
}

Drived::~Drived(){
	std::cout<<"~Drived()"<<std::endl;
}

void Drived::display(){
	//成员变量_a在子类中是私有的，无法直接访问
	std::cout<<"_a = "<<getA()<<",_b = "<<_b<<",_c = "<<_c<<",_d = "<<_d<<std::endl;
}

int Drived::getD(){
	return _d;
}

int main(){
	Drived d(1,2,3,4);
	d.display();	
	return 0;
}
