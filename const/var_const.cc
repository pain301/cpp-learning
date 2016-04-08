#include <iostream>

#define MAX 1/0

int main(void){

	//必须要进行初始化
	const int cons = 30;

	//宏定义错误到运行时才会检测到
	//std::cout<<"MAX = "<<MAX<<std::endl;
	std::cout<<"cons = "<<cons<<std::endl;

	int val1 = 23;
	int val2 = 32;
	
	//point to const,常量指针
	const int *p = &val1;
	std::cout<<"*p = "<<*p<<std::endl;
	//*p = 24;
	p = &val2;
	std::cout<<"*p = "<<*p<<std::endl;

	//const pointer,指针常量
	//声明的时候一定要赋初始值
	int* const q = &val1;
	std::cout<<"*q = "<<*q<<std::endl;
	*q = 100;
	//q = &val2;
	std::cout<<"*q = "<<*q<<std::endl; 
	
	//双重const
	const int * const r = &val2;
	std::cout<<"*r = "<<*r<<std::endl;
	//r = &val1;
	//std::cout<<"*r = "<<*r<<std::endl;
	
	return 0;	
}
