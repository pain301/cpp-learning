#include <iostream>

class Point{
private:
	int _x;
	int _y;
public:
	Point();
	//防止隐式转换
	explicit Point(int ,int = 0);
	Point(const Point &);
	
};

Point::Point(){
	std::cout<<"Point()"<<std::endl;
}

Point::Point(int x,int y):_x(x),_y(y){
	std::cout<<"Point(int,int)"<<std::endl;
}

Point::Point(const Point &point){
	_x = point._x;
	_y = point._y;
	std::cout<<"Point(const Point &)"<<std::endl;
}

int main(){
	Point p1;
	Point p2(1,2);
	//先调用有参构造函数，产生临时对象，再调用拷贝构造函数赋值
	//Point p3 = 1;
	return 0;
}
