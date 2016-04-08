#include <iostream>
#include <functional>

int add(int x,int y){
	return x+y;
}

class A{
public:
	int add(int x,int y){
		std::cout<<"A::add()"<<std::endl;
		return x+y;
	}
};

int main(){
	auto add1 = std::bind(add,10,std::placeholders::_1);
	std::cout<<add1(20)<<std::endl;
	A a;
	auto add2 = std::bind(&A::add,a,std::placeholders::_1,
				std::placeholders::_2);
	std::cout<<add2(3,4)<<std::endl;
	return 0;
}
