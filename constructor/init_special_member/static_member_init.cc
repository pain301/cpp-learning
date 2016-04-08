#include <iostream>

class Computer{
private:
	double _price;
	static double total;
public:
	Computer(double price = 0);
	~Computer();
	void print();
	static void printTotal();
};

double Computer::total = 0;

Computer::Computer(double price):_price(price){
	std::cout<<"Computer create"<<std::endl;
	total+=_price;
}

void Computer::print(){
	std::cout<<"price = "<<_price<<std::endl;
	std::cout<<"total = "<<total<<std::endl;
} 

void Computer::printTotal(){
	//在静态成员函数中无法使用普通成员变量，因为没有this指针
	//std::cout<<"price = "<<_price<<std::endl;
	//也无法调用普通成员函数
	//print();
	std::cout<<"total = "<<total<<std::endl;
}

Computer::~Computer(){
	std::cout<<"Computer destroy"<<std::endl;
	total-=_price;
}

int main(){
	Computer c1(20);
	c1.print();
	{
		Computer c3(40);
		c3.print();
	}
	//直接通过类名访问静态成员函数
	Computer::printTotal();
	Computer c2(33);
	c2.print();
	return 0;
}
