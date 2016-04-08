#include <iostream>
#include <fstream>
#include <stdlib.h>

int main(void){
	//默认指向文件开头
	//std::ifstream src("hello");
	//定位到文件末尾
	std::ifstream src("hello",std::ios::ate);
	if(!src.good()){
		std::cout<<"src error!"<<std::endl;
		exit(-1);
	}
	std::cout<<"offset = "<<src.tellg()<<std::endl;
	std::string str;
	getline(src,str);
	std::cout<<"str = "<<str<<std::endl;
	return 0;
}

