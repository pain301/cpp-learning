#include <iostream>

using namespace std;

//extern int num ;

int num = 100;

namespace {
	//shielding scope
	int num = 200;
	void no_name_fun(){
		cout<<"no name fun"<<endl;
	}
}

namespace B{
	int num = 3;
	void dispB(){
		cout<<"This is B"<<endl;
	}
}

namespace A{
	int num = 2;

	void dispA(){
		int num = 1;
		cout<<"THis is A"<<endl;
		cout<<"A function space num = "<<num<<endl;
		cout<<"A space num = "<<A::num<<endl;
		cout<<"B space num = "<<B::num<<endl;
		cout<<"extern num = "<<::num<<endl;
		cout<<"no name number = "<<::num<<endl;
		::no_name_fun();
	}

	void disp(){
		cout<<"This is disp"<<endl;
	}
}

void disp(){
	cout<<"out disp"<<endl;
}

using namespace A;

int main(){
	::disp();
	dispA();
	return 0;
}
