#include <iostream>

int main(){
	double pi = 3.1415926;
	
	int tmp1 = static_cast<int>(pi);
	double tmp2 = static_cast<double>(tmp1);	

	std::cout<<"pi = "<<pi<<std::endl;
	std::cout<<"tmp1 = "<<tmp1<<std::endl;
	std::cout<<"tmp2 = "<<tmp2<<std::endl;

	return 0;
}
