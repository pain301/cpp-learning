#include <iostream>
#include <limits>
#include <stdlib.h>

using std::cin;

int main(){
	int num;
	while(cin>>num,!cin.eof()){
		if(cin.bad()){
			std::cout<<"system error"<<std::endl;
			exit(-1);
		}
		if(cin.fail()){
			std::cout<<"try again"<<std::endl;
			std::cin.clear();
			//不清楚缓冲区的数据，则不符合的数据会继续读入，循环出错
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			continue;
		}
		std::cout<<"num = "<<num<<std::endl;
	}
	return 0;
}
