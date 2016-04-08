#include <iostream>
#include <stdio.h>

class Point{
private:
	const int _x;
	const int _y;
	const int &_refer_in;
	int &_refer_out;
public:
	Point(int &z,int x = 0,int y = 0);
	Point(const Point &);
	void print();
	~Point();
};

//常量与引用成员变量的初始化必须要在初始化列表中进行
//对引用初始化时，形参也应该是引用
Point::Point(int &z,int x,int y):_x(x),_y(y),_refer_in(_x),_refer_out(z){
	std::cout<<"construction"<<std::endl;	
	++_refer_out;
}

//复制构造函数中也在初始化列表中初始化引用成员变量，常量
Point::Point(const Point &point):_x(point._x),_y(point._y),
				_refer_in(point._refer_in),
				_refer_out(point._refer_out){
	std::cout<<"copy construction"<<std::endl;
}

void Point::print(){
	std::cout<<"_x = "<<_x<<std::endl;
	std::cout<<"_y = "<<_y<<std::endl;
	std::cout<<"_refer_in = "<<_refer_in<<std::endl;
	std::cout<<"_refer_out = "<<++_refer_out<<std::endl;
}

Point::~Point(){
	std::cout<<"distruction Point"<<std::endl;
}

int main(){
	int val = 10;
	Point p1(val,1,1);
	p1.print();
	Point p2 = p1;
	p2.print();
	val = 100;
	std::cout<<std::endl;
	p1.print();
	p2.print();
	return 0;
}
