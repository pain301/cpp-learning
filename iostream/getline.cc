#include <iostream>
#include <stdio.h>

using std::string;

int main(void){
	char str[100];
	
	//C语言中输入输出
	#if 0
	while((scanf("%s",str))!=EOF){
		printf("%s\n",str);	
	}
	#endif
	
	//C++中输入输出
	#if 0
	string str1;
	while((std::cin>>str1)){
		std::cout<<"str1 = " << str1 << std::endl;
	}
	#endif

	//读入一行数据
	string str2;
	while(getline(std::cin,str2)){
		std::cout<<"str2 = " << str2 <<std::endl;
	}
	return 0;
}
