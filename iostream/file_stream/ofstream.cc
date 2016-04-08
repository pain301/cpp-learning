#include <iostream>
#include <fstream>

int main(){
	//默认删除原有数据
	std::ofstream src("hello");
	//定位到文件末尾
	//std::ofstream src("hello",std::ios::app);
	if(!src.good()){
		std::cout<<"src error!"<<std::endl;
	}
	src<<"hello world"<<std::endl;
	//当前偏移位置
	std::cout<<"offset = "<<src.tellp()<<std::endl;
	src.close();
	return 0;
}
