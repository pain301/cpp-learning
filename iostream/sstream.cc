#include <iostream>
#include <sstream>

int main(){
	std::stringstream ss;
	int val1 = 10;
	int val2 = 20;
	//输入到字符串流
	ss<<"val1 = "<<val1<<" val2 = "<<val2;
	//将字符串流中的读到一个字符串中
	std::string str = ss.str();
	std::cout<<str<<std::endl;
	//将字符串流中的数据输入到字符串中
	//以空格分隔
	while(ss>>str){
		std::cout<<str<<std::endl;	
	}
	return 0;
}
