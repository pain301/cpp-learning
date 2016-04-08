#include <iostream>

int arr[5] = {1,2,3,4,5};

int& test1(int i){
	return arr[i];
}

//不能返回对局部变量的引用
int& test2(){
	int val = 3;
	return val;
}

//不能返回局部变量的指针
int* test4(){
	int temp = 5;
	return &temp;
}

//易造成内存泄露
int& test3(){
	int *p = new int(4);
	return *p;
}

int main(void){
	int a = 10;
	int b = 20;

	//引用必须初始化	
	int &refera = a;
	std::cout<<"&refera = "<<refera<<std::endl;
	refera = b; 
	std::cout<<"&refera = "<<refera<<std::endl;
	std::cout<<"a = "<<a<<std::endl;
	
	//非const引用不可以用常量赋值
	//int &referb = 10;

	const int &referb = 10;
	std::cout<<"referb = "<<referb<<std::endl;
	
	std::cout<<"test1(i) = "<<test1(1)<<std::endl;
	std::cout<<"test2() = "<<test2()<<std::endl;
	int & refer = test3();
	std::cout<<"test3() = "<<refer<<std::endl;
	std::cout<<"test4() = "<<*test4()<<std::endl;
	
	//不常见
	delete &refer;
	return 0;
}
