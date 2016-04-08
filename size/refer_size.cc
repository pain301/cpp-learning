#include <iostream>

class Cell{
private:
	int a;
	char b;
	float c;
	double d;
	short e[6];
	char &f;
	double &g;
	static int h;
public:
	Cell();
};

Cell::Cell():f(b),g(d){

}

int Cell::h = 10;

//引用占8个字节
class A{
private:
	short a[5];
	char &b;
	double c;
};

class B{
	char &c;
};

class C{
	char c;
};

class D{
	int i;
};

class E{
	int &i;
};

int main(){
	Cell c;
	std::cout<<"sizeof(c) = "<<sizeof(c)<<std::endl;
	std::cout<<"sizeof(A) = "<<sizeof(A)<<std::endl;
	std::cout<<"sizeof(B) = "<<sizeof(B)<<std::endl;
	std::cout<<"sizeof(C) = "<<sizeof(C)<<std::endl;
	std::cout<<"sizeof(D) = "<<sizeof(D)<<std::endl;
	std::cout<<"sizeof(E) = "<<sizeof(E)<<std::endl;
	char a = 'a';
	char &b = a;
	std::cout<<"char refer = "<<sizeof(b)<<std::endl;
	return 0;
}
