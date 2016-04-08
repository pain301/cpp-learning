#include <iostream>

class Point{
private:
	int _x;
	int _y;
public:
	Point(int x = 0,int y = 0);
	~Point();
	void print();
};

Point::Point(int x,int y):_x(x),_y(y){
}

Point::~Point(){
}

void Point::print(){
	std::cout<<"Point("<<_x<<","<<_y<<")";
}

class Line{
private:
	//对象成员的初始化需要在初始化列表中
	Point _start;
	Point _end;
public:
	Line(const Point &,const Point &);
	Line(int x1=0,int y1=0,int x2=0,int y2=0);
	Line(const Line &);
	~Line();
	void draw();
};

Line::Line(const Point &start,const Point &end):_start(start),_end(end){
	std::cout<<"Line create1"<<std::endl;
}

//Point调用默认的拷贝构造函数
Line::Line(int x1,int y1,int x2,int y2):_start(Point(x1,y1)),_end(Point(x2,y2)){
	std::cout<<"Line create2"<<std::endl;
}

Line::Line(const Line &line):_start(line._start),_end(line._end){
	std::cout<<"Line creat3"<<std::endl;
}

Line::~Line(){
	std::cout<<"Line destory"<<std::endl;
}

void Line::draw(){
	_start.print();
	std::cout<<" to ";
	_end.print();
}

int main(){
	Point p1;
	Point p2(2,3);
	Line line1(p1,p2);
	Line line2(1,2,3);
	Line line3 = line2;
	line3.draw();
	std::cout<<std::endl;
	return 0;
}
