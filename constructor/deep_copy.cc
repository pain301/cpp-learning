#include <iostream>
#include <string.h>
#include <stdio.h>

class Computer{
private:
	double _price;
	char *_brand;
public:
	Computer();
	Computer(double,char *);
	//如果参数是对象，会导致无限递归，最终栈溢出
	Computer(const Computer &);
	~Computer();
	Computer& operator=(const Computer&);
	void print();
};

Computer::Computer(){
	std::cout<<"无参构造函数调用"<<std::endl;
}

Computer::Computer(double price,char *brand):_price(price){
	std::cout<<"有参构造函数调用"<<std::endl;
	_brand = new char[strlen(brand)+1];
	strcpy(_brand,brand);
}

Computer::Computer(const Computer &computer):_price(computer._price){
	std::cout<<"拷贝构造函数调用"<<std::endl;
	_brand = new char[strlen(computer._brand)+1];
	strcpy(_brand,computer._brand);
}

Computer::~Computer(){
	delete []_brand;
	std::cout<<"~Computer()"<<std::endl;
}

void Computer::print(){
	printf("%p\n",_brand);
	std::cout<<"brand: "<<_brand<<std::endl;
	std::cout<<"price: "<<_price<<std::endl;
}

Computer & Computer::operator=(const Computer & computer){
	std::cout<<"operator=(const Computer &)"<<std::endl;	
	//防止自复制
	if(this==&computer){
		std::cout<<"自复制"<<std::endl;
	}
	delete []_brand;
	_brand = new char[strlen(computer._brand)+1];
	_price = computer._price;
	strcpy(_brand,computer._brand);
	return *this;
}

int main(void){
	Computer lenovo(4500,"lenovo");
	Computer mac(6000,"mac");
	Computer thinkPad1 = lenovo;
	Computer thinkPad2 = lenovo; 
	lenovo.print();
	mac.print();
	thinkPad1.print();
	thinkPad2.print();
	thinkPad2 = mac;
	thinkPad2.print();
	mac = mac;
	return 0;
}
