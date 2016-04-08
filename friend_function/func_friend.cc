#include <iostream>
#include <cmath>

class Point{
	friend double dist(const Point &,const Point &);
private:
	int _x;
	int _y;
public:
	Point(int x = 0,int y = 0);
	void print();
};

Point::Point(int x,int y):_x(x),_y(y){

}

void Point::print(){
	std::cout<<"point("<<_x<<","<<_y<<")"<<std::endl;
}

double dist(const Point &p1,const Point &p2){
	return sqrt((p1._x-p2._x)*(p1._x-p2._x)+(p1._y-p2._y)*(p1._y-p2._y));
}

int main(){
	Point p1;
	Point p2(3,4);
	p1.print();	
	p2.print();
	std::cout<<"distance p1 and p2 is "<<dist(p1,p2)<<std::endl;
	return 0;
}
