#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Singleton{
private:
	//单例模式，类共享，定义为静态变量
	//因为在方法getInstance中访问，所以需要定义为静态变量
	static Singleton *p;
public:
	//在对象创建之前就会访问得到，因此为类函数
	static Singleton * getInstance();
	static void destroy();
	void print();
private:
	Singleton();
	Singleton(const Singleton &);
	//Singleton & operator=(const Singleton &);
	//私有化防止栈对象的创建
	~Singleton();
};

Singleton* Singleton::p = NULL;

Singleton::Singleton(){
	std::cout<<"Singleton create"<<std::endl;
} 

Singleton::~Singleton(){
	std::cout<<"Singleton destroy"<<std::endl;
}

Singleton* Singleton::getInstance(){
	if(p==NULL){
		p = new Singleton();
	}
	return p;
}

void Singleton::destroy(){
	delete p;
}

void Singleton::print(){
	std::cout<<"print"<<std::endl;
}

int main(){
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	
	//通过赋值运算符造破坏了单例模式
	Singleton *p3 = (Singleton *)malloc(sizeof(Singleton));
	*p3 = *p2;
	printf("p3 = %p\n",p3);
	p1->destroy();
	return 0;
}
