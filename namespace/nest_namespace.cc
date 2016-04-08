#include <iostream>

int num = 0;

namespace A{
	int num = 1;
	namespace B{
		int num = 3;
		void disp(){
			int num = 4;
			std::cout<<"extern num"<<::num<<std::endl;	
			std::cout<<"A Space num"<<A::num<<std::endl;	
			std::cout<<"B Space num"<<B::num<<std::endl;	
			std::cout<<"B Fucntion num"<<num<<std::endl;			
		}
	}
}

int main(void)
{
	A::B::disp();
	return 0;
}
