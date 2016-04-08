#include "line.hh"
#include <iostream>

class Line::Impl{
private:
	class Point{
		private:
			int _x;
			int _y;
		public:
			Point(int x = 0,int y = 0);
			void print();
	};
private:
	Point _start;
	Point _end;
public:
	Impl(int x1=0,int y1=0,int x2=0,int y2=0);
	void print();
};//end of Impl

//通过Impl操作
Line::Impl::Impl(int x1,int y1,int x2,int y2):
			_start(Point(x1,y1)),
			_end(Point(x2,y2)){
	
}

void Line::Impl::print(){
	_start.print();
	_end.print();
}

Line::Impl::Point::Point(int x,int y):_x(x),_y(y){

}

void Line::Impl::Point::print(){
	std::cout<<"point("<<_x<<","<<_y<<")"<<std::endl;
}

Line::Line(int x1,int y1,int x2,int y2){
	p = new Impl(x1,y1,x2,y2);
}

Line::~Line(){
	delete p;
}

void Line::print(){
	p->print();
}
