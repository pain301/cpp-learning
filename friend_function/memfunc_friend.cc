#include <iostream>
#include <cmath>

//先声明
class Point;

class Line{
public:
	double dist(const Point &p1,const Point &p2);
};

class Point{
	friend double Line::dist(const Point &,const Point &);
private:
	int _x;
	int _y;
public:
	Point(int x=0,int y=0);
};

Point::Point(int x,int y):_x(x),_y(y){

}

double Line::dist(const Point &p1,const Point &p2){
	return sqrt((p1._x-p2._x)*(p1._x-p2._x)+(p1._y-p2._y)*(p1._y-p2._y));
}

int main(){
	Point p1(0,0);
	Point p2(3,4);
	Line line;
	std::cout<<"p1 and p2 distance is "<<line.dist(p1,p2)<<std::endl;
	return 0;
}
