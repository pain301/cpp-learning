#include <iostream>
#include <stdlib.h>

int main(void){
	
	//malloc只会申请内存空间，通过库函数实现
	int *p = (int *)malloc(sizeof(int));
	*p = 10;
	std::cout<<"*p = "<<*p<<std::endl;
	free(p);

	//new申请内存空间，同时初始化
	//new是一个表达式
	int *q = new int(10);
	*q = 20;
	std::cout<<"*q = "<<*q<<std::endl;
	delete q;

	int *r = new int();
	//int *r = new int;
	std::cout<<"*r = "<<*r<<std::endl;
	//也不会报错
	delete []r;

	//申请一个数组
	int *t = new int[10];
	delete []t;

	return 0;
}
