#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

class CharArray{
private:
	int size;
	char *p;
public:
	CharArray();
	CharArray(const char *);
	~CharArray();
	char & operator[](int);
	void print();
	int getSize();
};

CharArray::CharArray(){

}

CharArray::CharArray(const char *str){
	size = strlen(str);
	p = new char[size];
	strncpy(p,str,size);
}

CharArray::~CharArray(){
	size = 0;
	delete []p;
}

void CharArray::print(){
	std::cout<<"array: "<<p<<std::endl;
}

char & CharArray::operator[](int index){
	//全局静态区，生命周期超过函数
	static char nullchar  = '\0';
	if(index==size||index<0){
		fprintf(stderr,"out of array");
		return nullchar; 
	}else{
		return p[index];
	}
}

int CharArray::getSize(){
	return size;
}

int main(){
	CharArray ca1 = "hello world";
	ca1.print();
	int i = 0;
	while(i<ca1.getSize()){
		char tmp = ca1[i];
		std::cout<<":"<<tmp;
		i++;
	}
	std::cout<<std::endl;
	std::cout<<"----------------"<<std::endl;
	return 0;
}
