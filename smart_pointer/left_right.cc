#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int main(){
	int a = 10;
	int b = 20;
	int *p = &a;
	vector<int> vc;
	vc.push_back(1);
	string str1 = "hello";
	string str2 = "world";
	const int &m = 1;
	
	&a;
	&b;
	&(++a);
	&p;
	&(*p);
	&(vc[0]);
	&str1;
	&m;

	//&100;	
	//&(a++);
	//&(a+b);
	
	//取临时变量的值	
	//&(str1+str2);
	//&string("hello");
	return 0;
}
