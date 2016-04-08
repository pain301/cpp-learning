#include <iostream>
#include <stdio.h>

int main(){
	bool flag1 = 100;
	bool flag2 = -1;
	bool flag3 = 0;

	std::cout<<"flag1 = "<<flag1<<std::endl;
	std::cout<<"flag2 = "<<flag2<<std::endl;
	std::cout<<"flag3 = "<<flag3<<std::endl;

	bool flag4 = true;
	bool flag5 = false;
	std::cout<<"flag4 = "<<flag4<<std::endl;
	std::cout<<"flag5 = "<<flag5<<std::endl;
	
	//sizeof是一个关键字，不是函数
	std::cout<<"sizeof(bool) = "<<sizeof(bool)<<std::endl;
	std::cout<<"sizeof(flag1) = "<<sizeof flag1<<std::endl;
	printf("sizeof(bool) = %d\n",sizeof flag1);
	return 0;
}
