#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

template<typename T>
class Singleton{
private:
	static T* pInstance;
	Singleton();
	~Singleton();
	class AutoRelease{
		public:
			AutoRelease();
			~AutoRelease();
	};
public:
	static T* getInstance();	
	static void destroy();
	static AutoRelease autoRelease;
};

template<typename T>
T* Singleton<T>::pInstance = NULL;

//template<typename T>
//Singleton<T>::AutoRelease Singleton<T>autoRelease;

template<typename T>
Singleton<T>::Singleton(){
	std::cout<<"Singleton()"<<std::endl;
}

template<typename T>
Singleton<T>::~Singleton(){
	std::cout<<"~Singleton()"<<std::endl;
}

template<typename T>
T* Singleton<T>::getInstance(){
	//::atexit(destroy);  //注册，在main函数结束之后执行destroy函数
	if(pInstance==NULL){
		pInstance = new T;
	}
	return pInstance;
}

template<typename T>
Singleton<T>::AutoRelease::AutoRelease(){
	std::cout<<"AutoRelease()"<<std::endl;
}

template<typename T>
Singleton<T>::AutoRelease::~AutoRelease(){
	std::cout<<"~AutoRelease()"<<std::endl;
	delete pInstance;
}

template<typename T>
void Singleton<T>::destroy(){
	if(pInstance!=NULL){
		delete pInstance;
		pInstance = NULL;
		std::cout<<"destroy"<<std::endl;
	}
}

int main(){
	int *p1 = Singleton<int>::getInstance();
	int *p2 = Singleton<int>::getInstance();

	printf("p1 address is %p\n",p1);
	printf("p2 address is %p\n",p2);
	
	return 0;
}
