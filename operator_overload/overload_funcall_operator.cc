#include <iostream>

class Fun{
public:
	//函数调用运算符重载
	void operator()(int x,int y = 0);
	int operator()(double x);
	double operator()(double x,double y,double z);
};

void Fun::operator()(int x,int y){
	std::cout<<"x = "<<x<<","<<"y = "<<y<<std::endl;
}

int Fun::operator()(double x){
	std::cout<<"x = "<<x<<std::endl;
}

double Fun::operator()(double x,double y,double z){
	double res = (x+y+z)/3;
	return res;
}

int main(){
	Fun fun;
	//函数对象
	fun(123);
	std::cout<<"avg = "<<fun(3.14,5.74,9.22)<<std::endl;
	return 0;
}
