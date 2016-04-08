#include <iostream>
#include <limits>

using std::cin;

//打印输入流的状态
void printCinStatus(){
	std::cout<<"cin bad = "<<cin.bad()<<std::endl;
	std::cout<<"cin fail = "<<cin.fail()<<std::endl;
	std::cout<<"cin eof = "<<cin.eof()<<std::endl;
	std::cout<<"cin good = "<<cin.good()<<std::endl;
}

int main(){
	printCinStatus();
	int num;
	//输入非数字状态fail
	//输入结束状态fail&eof
	while(cin>>num){
		std::cout<<num<<std::endl;
	}
	printCinStatus();
	//恢复状态,此时缓冲区可能还有数据
	cin.clear();
	//清除缓冲区中的数据
	//如果是eof则不执行
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//清除缓冲区'\n'之前的数据
	//cin.ignore(1024,'\n');
	std::cout<<"-------------"<<std::endl;
	printCinStatus();
	std::string s;
	cin>>s;
	std::cout<<s<<std::endl;
	return 0;
}
