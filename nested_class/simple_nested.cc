#include <iostream>

class Line{
public:
	class Point{
		private:
			int _x;
			int _y;
		public:
			Point(int x=0,int y=0);
			Point(const Point &);
			void print();
	};
	Line(int x1=0,int y1=0,int x2=0,int y2=0);
	Line(const Point &p1,const Point &p2);
	void print();
private:
	Point p1;
	Point p2;
};

Line::Point::Point(int x,int y):_x(x),_y(y){

}

Line::Point::Point(const Point &p):_x(p._x),_y(p._y){

}

void Line::Point::print(){
	std::cout<<"Point("<<_x<<","<<_y<<")"<<std::endl;
}

Line::Line(int x1,int y1,int x2,int y2):p1(Point(x1,y1)),p2(Point(x2,y2)){

}

Line::Line(const Point &pp1,const Point &pp2):p1(pp1),p2(pp2){

}

void Line::print(){
	p1.print();
	p2.print();	
}

int main(){
	Line line(1,2,3,4);
	line.print();
	return 0;
}
