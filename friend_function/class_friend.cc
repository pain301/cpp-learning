#include <iostream>
#include <cmath>

class Point;

class Line{
public:
	double dist(const Point &,const Point &);
	void set(Point &p,int a,int b);
};

class Point{
	friend class Line;
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

void Line::set(Point &p,int a,int b){
	p._x = a;
	p._y = b;
}

int main(){
	Point p1;
	Point p2;
	Line line;
	line.set(p2,3,4);
	std::cout<<"line dist is "<<line.dist(p1,p2)<<std::endl;
	return 0;	
}
