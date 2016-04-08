#include <iostream>

namespace B{
	int num = 23;	
}

namespace A{
	void disp(){
		std::cout<<"disp"<<std::endl;
		std::cout<<"B number"<<B::num<<std::endl;
	}
}

namespace B{
	void disp(){
		A::disp();
	}
}

int main(){
	B::disp();
	return 0;	
}

