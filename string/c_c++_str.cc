#include <string.h>
#include <iostream>
#include <stdio.h>

using std::string;

int main(void){
	//C语言中的字符串
	char *p = "hello world";
	char str[1024] = "hello c++";
	
	printf("%s\n",p);
	printf("%s\n",str);
	//C语言中字符串的链接
	strcat(str,p);
	printf("%s\n",str);

	//C语言中的字符串截取
	//让拷贝进来的字符串能够结束
	char buf[1024] = {0};
	char *tmp = strstr(str,"c++");
	printf("%s\n",tmp);
	strncpy(buf,tmp,3);
	printf("%s\n",buf);

	//C++中的字符串
	string s1 = "C++ string";
	string s2 = "iostream";
	//C++中字符串的链接
	string s3 = s1+s2;
	string s4 = s3+'O';
	std::cout<<"s1 = "<<s1<<std::endl;
	std::cout<<"s2 = "<<s2<<std::endl;
	std::cout<<"s3 = "<<s3<<std::endl;
	std::cout<<"s4 = "<<s4<<std::endl;
	s4.push_back('P');
	std::cout<<"s4 = "<<s4<<std::endl;

	//C++中字符串截取
	string s5 = s4.substr(s4.find("C++"),3);
	std::cout<<"s5 = "<<s5<<std::endl;
	
	//下标遍历
	for(int i = 0;i<s5.size();i++){
		std::cout<<s5[i]<<" ";
	}
	std::cout<<std::endl;

	//迭代器遍历
	string::iterator it;
	for(it = s5.begin();it!=s5.end();it++){
		std::cout<<*it<<" ";
	}
	std::cout<<std::endl;

	return 0;
}
