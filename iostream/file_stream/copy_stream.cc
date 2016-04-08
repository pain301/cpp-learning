#include <iostream>
#include <fstream>
#include <stdlib.h>

int main(){
	std::ifstream src("ifstream.cc");
	if(!src.good()){
		std::cout<<"src error!"<<std::endl;
		exit(-1);
	}
	std::ofstream dst("test.cc");
	if(!dst.good()){
		std::cout<<"dst error!"<<std::endl;
		exit(-2);
	}
	std::string str;
	//getline会过滤掉'\n'
	while(getline(src,str)){
		//加上换行
		//dst<<str<<std::endl;	
		dst<<str;
	}
	src.close();
	dst.close();
	return 0;
}
