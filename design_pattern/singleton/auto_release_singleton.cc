#include <stdio.h>
#include <iostream>

class Singleton{
	class AutoRelease{
		public:
			AutoRelease();
			~AutoRelease();
	};
private:
	static Singleton *pInstance;
	Singleton();
	~Singleton();
	//必须为static，存在全局静态区
	//否则就是Singleton对象的成员对象，存放在堆空间，程序结束pInstance不释放便不会执行其析构函数
	static AutoRelease autoRelease;
public:
	static Singleton* getInstance();
	static void destroy();
};

Singleton* Singleton::pInstance = NULL;

Singleton::AutoRelease Singleton::autoRelease;

Singleton::Singleton(){
	std::cout<<"Singleton created!"<<std::endl;
}

Singleton::~Singleton(){
	std::cout<<"~Singleton destroy"<<std::endl;
}

Singleton* Singleton::getInstance(){
	if(pInstance == NULL){
		pInstance = new Singleton();
	}
	return pInstance;	
}

void Singleton::destroy(){
	if(pInstance!=NULL)
		delete pInstance;
}

Singleton::AutoRelease::AutoRelease(){
	std::cout<<"Singleton::AutoRelease"<<std::endl;
}

Singleton::AutoRelease::~AutoRelease(){
	std::cout<<"Singleton::~AutoRelease"<<std::endl;
	Singleton::destroy();	
}

int main(){
	Singleton *sp1 = Singleton::getInstance();
	Singleton *sp2 = Singleton::getInstance();
	printf("sp1 address = %p\n",sp1);
	printf("sp2 address = %p\n",sp2);
	return 0;
}
