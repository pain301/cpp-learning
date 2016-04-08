#include <iostream>

class Point{
private:
	int _x;
	int _y;
public:
	Point();
	Point(int x,int y);
	Point(const Point &);
	~Point();
	Point & operator=(const Point &);
	void print();
};

Point::Point(){
	std::cout<<"Point() constructor"<<std::endl;
}

Point::Point(int x,int y):_x(x),_y(y){
	std::cout<<"Point(int ,int) constructor"<<std::endl;
}

Point::Point(const Point &point):_x(point._x),_y(point._y){
	std::cout<<"Point(const Point &) constructor"<<std::endl;
}

Point& Point::operator=(const Point &point){
	_x = point._x;
	_y = point._y;
	std::cout<<"operator=(const Point &)"<<std::endl;
}

void Point::print(){
	std::cout<<"Point._x = "<<_x<<std::endl;
	std::cout<<"Point._y = "<<_y<<std::endl;
}

Point::~Point(){
	std::cout<<"~Point"<<std::endl;
}

void function1(Point p){
	std::cout<<"实参为形参赋值"<<std::endl;
}

Point function2(){
	std::cout<<"函数返回对象"<<std::endl;
	Point p;
	return p;
}

//编译参数-fno-elide-constructors
//观察拷贝构造函数的调用时机
int main(void){
	std::cout<<"普通构造函数调用"<<std::endl;
	Point p1;
	std::cout<<"有参构造函数调用"<<std::endl;
	Point p2(10,20);
	std::cout<<"拷贝构造函数调用"<<std::endl;
	Point p3(p2);
	std::cout<<"拷贝构造函数赋值方式调用"<<std::endl;
	Point p4 = p1;
	std::cout<<"拷贝构造函数调用之实参传递给形参"<<std::endl;
	function1(p4);
	std::cout<<"拷贝构造函数调用之函数返回"<<std::endl;
	Point p5 = function2();
	std::cout<<"赋值运算符函数重载调用"<<std::endl;
	p1 = p2;
	return 0;
}

