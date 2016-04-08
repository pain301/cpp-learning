#include <iostream>
#include <stdio.h>


//C++支持函数重载,其实现原理叫名字改编（name mangling）
//根据函数参数的类型，个数，顺序不同来进行名字改编
//名字改编与函数返回值无关

#ifdef __cplusplus
extern "C"{
#endif
	int add(int a,int b){
		printf("c add(int,int)\n");
		return a+b;	
	}
	
	int sub(int a,int b){
		printf("c sub(int,int)\n");
		return a-b;
	}
#ifdef __cplusplus
}
#endif

int add(int a,int b,int c){
	std::cout<<"add(int,int,int)"<<std::endl;
	return a+b+c;
}

double add(double a,double b){
	std::cout<<"add(double,double)"<<std::endl;
	return a+b;
}

int main(){
	add(2,3);
	add(2,3,4);
	add(2.12,4.34);
	return 0;
}
