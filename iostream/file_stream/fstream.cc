#include <iostream>
#include <fstream>
#include <stdlib.h>

int main(){
	//默认为读写模式 std::ios::in|std::ios::out
	//读写模式下文件必须存在，否则出错
	//不会清空文件，直接覆盖原来的内容
	//std::fstream stream("hello");
	//定位到文件的末尾位置,ate与app模式细微差别
	//std::fstream stream("hello",std::ios::in|std::ios::out|std::ios::ate);
	std::fstream stream("hello",std::ios::in|std::ios::out|std::ios::app);
	if(!stream.good()){
		std::cout<<"src error!"<<std::endl;
		exit(-1);
	}
	//查看文件位置
	std::cout<<"offset = "<<stream.tellg()<<std::endl;
	std::cout<<"offset = "<<stream.tellp()<<std::endl;
	int val;
	for(int i = 0;i<5;i++){
		std::cin>>val;
		stream<<val<<" ";
	}
	std::cout<<"offset = "<<stream.tellg()<<std::endl;
	std::cout<<"offset = "<<stream.tellp()<<std::endl;
	stream.close();
	return 0;
}
