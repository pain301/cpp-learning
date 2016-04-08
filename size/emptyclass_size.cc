#include <iostream>
#include <string.h>

class Computer{
private:
	//字节数：104+8
	char _brand[100];
	//成员变量定义时不能初始化
	double _price ;
public:
	void print();
	void setBrand(char *);
	void setPrice(double price);
	//类内部使用函数
	void inner(){
		std::cout<<"hello world"<<std::endl;	
	}
};

class Computer1{
private:
	//字节数：96+8
	char _brand[96];
	double _price ;
public:
	void print();
	void setBrand(char *);
	void setPrice(double price);
};

void Computer::print(){
	std::cout<<"Computer Brand:"<< _brand<<std::endl;
	std::cout<<"Computer Price:"<< _price<<std::endl;
}

void Computer::setBrand(char *brand){
	strncpy(_brand,brand,strlen(brand)+1);
	//strcpy(_brand,brand);
}

void Computer::setPrice(double price){
	_price = price;
}

class Empty{};

//以最长的为准，即每8个字节对准
struct A{
	int a;
	char b;
	double c;
	short e;
};

struct B{
	char a;
	short b;
	int c;
	double e;	
};

struct C{
	int a;
	char b;
	int c;
	short e;
};

int main(void){
	//struct A中数据默认访问权限是public
	//类中的默认访问权限是private
	A a;
	a.a = 100;
	a.b = 'c';
	a.c = 3.14;
	
	std::cout<<"sizeof(A) = "<<sizeof(A)<<std::endl;
	std::cout<<"sizeof(B) = "<<sizeof(B)<<std::endl;
	std::cout<<"sizeof(C) = "<<sizeof(C)<<std::endl;
	std::cout<<"sizeof(Computer) = "<<sizeof(Computer)<<std::endl;
	std::cout<<"sizeof(Empty) = "<<sizeof(Empty)<<std::endl;
	return 0;
}
