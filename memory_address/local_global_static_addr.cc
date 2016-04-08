#include <iostream>
#include <stdio.h>

int a;
int b;
static int c;
static int d;

const int m = 10;
char *p = "hello";
char str1[] = "hello";

int main(void){
	int e;
	int f;
	static int g;
	static int h;
	const int n = 20;
	char *q = "hello";
	char str2[] = "hello";

	std::cout<<"全局变量"<<std::endl;
	std::cout<<"&a = "<<&a<<std::endl;
	std::cout<<"&b = "<<&b<<std::endl;
	printf("p = %p\n",p);
	printf("str1 = %p\n",str1);

	std::cout<<"全局静态"<<std::endl;
	std::cout<<"&c = "<<&c<<std::endl;
	std::cout<<"&d = "<<&d<<std::endl;

	std::cout<<"全局常量"<<std::endl;
	std::cout<<"&m = "<<&m<<std::endl;

	std::cout<<"局部静态"<<std::endl;
	std::cout<<"&g = "<<&g<<std::endl;
	std::cout<<"&h = "<<&h<<std::endl;

	std::cout<<"局部变量"<<std::endl;
	std::cout<<"&e = "<<&e<<std::endl;
	std::cout<<"&f = "<<&f<<std::endl;
	
	std::cout<<"局部常量"<<std::endl;
	std::cout<<"&n = "<<&n<<std::endl;
	//常量区
	printf("q = %p\n",q);
	printf("str2 = %p\n",str2);
	
	return 0;
}
