#include <iostream>

class Point{
private:
	int rad;
	static int color;
public:
	void test1();
	void test2();
	void test3();
};

int Point::color = 10;

void Point::test1(){
	std::cout<<"test1"<<std::endl;
}

void Point::test2(){
	std::cout<<"test2"<<color<<std::endl;
}

void Point::test3(){
	std::cout<<"test3"<<rad<<std::endl;
}

int main(){
	Point *p = NULL;
	p->test1();
	p->test2();
	//p->test3();
	return 0;
}
