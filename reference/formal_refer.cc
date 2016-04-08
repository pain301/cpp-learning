#include <iostream>

void swap(int a,int b){
	int tmp = a;
	a = b;
	b = tmp;
}

//本质还是值传递，只不过传递的是变量的地址
void swap(int *a,int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//发生实参与形参的结合
//引用作为函数的参数时，没有复制开销，提高程序性能
void swap2(int &a,int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void){
	int a = 30;
	int b = 40;
	swap(a,b);
	std::cout<<"a = "<<a<<std::endl;	
	std::cout<<"b = "<<b<<std::endl;
	swap(&a,&b);
	std::cout<<"a = "<<a<<std::endl;	
	std::cout<<"b = "<<b<<std::endl;
	swap2(a,b);
	std::cout<<"a = "<<a<<std::endl;	
	std::cout<<"b = "<<b<<std::endl;
	return 0;
}
