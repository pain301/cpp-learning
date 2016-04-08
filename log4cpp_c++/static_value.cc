#include <iostream>

int main(){
	//内置宏定义，打印文件名，行号，函数名
	std::cout<<__FILE__<<std::endl;
	std::cout<<__LINE__<<std::endl;
	std::cout<<__func__<<std::endl;
	return 0;
}
