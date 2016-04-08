#include <iostream>

int main(){
	int i = 5;
	const int *pi = &i;
	
	std::cout<<"i = "<<i<<std::endl;
	std::cout<<"*pi = "<<*pi<<std::endl;

	int *p = const_cast<int *>(pi);
	*p = 10;
	
	std::cout<<"i = "<<i<<std::endl;
	std::cout<<"*pi = "<<*pi<<std::endl;
	std::cout<<"*p = "<<*p<<std::endl;

	std::cout<<std::endl;

	const int b = 30;
	const int *q = &b;

	std::cout<<"b = "<<b<<std::endl;
	std::cout<<"*q = "<<*q<<std::endl;

	int *s = const_cast<int*>(q);
	*s = 20;
	std::cout<<"b = "<<b<<std::endl;
	std::cout<<"*q = "<<*q<<std::endl;
	std::cout<<"*s = "<<*s<<std::endl;
	return 0;
}
