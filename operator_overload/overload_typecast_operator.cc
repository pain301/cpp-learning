#include <iostream>

class Point{
private:
	int _x;
	int _y;
public:
	Point(int x = 0,int y = 0);
	void print();
	//重载转换函数
	operator int();
};

Point::Point(int x,int y):_x(x),_y(y){
	std::cout<<"Point(int ,int)"<<std::endl;
}

void Point::print(){
	std::cout<<"x = "<<_x<<" y = "<<_y<<std::endl;
}

Point::operator int(){
	return _x+_y;
}

int main(){
	Point p(1,2);
	p.print();	
	int x = p;
	std::cout<<"x = "<<x<<std::endl;
	return 0;
}
