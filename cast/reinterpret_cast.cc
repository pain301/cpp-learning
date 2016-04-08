#include <iostream>

int main(){
	double pi = 3.14;
	double *p = &pi;
	
	int *i = reinterpret_cast<int*>(p);
	std::cout<<p<<std::endl;
	std::cout<<i<<std::endl;	
	
	std::cout<<"*p = "<<*p<<std::endl;
	std::cout<<"*i = "<<*i<<std::endl;

	return 0;
}
