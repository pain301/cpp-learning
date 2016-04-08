#include <iostream>
#include <stdlib.h>

class Point{
private:
	int _x;
	int _y;
public:
	Point(int x=0,int y=0);
	Point(const Point  &);
	void print();
	~Point();
private:
	//将此两个运算符私有化，阻止了通过堆创建对象
	static void * operator new(size_t size);
	static void operator delete(void *);
	static void * operator new[](size_t size);
};

Point::Point(int x,int y):_x(x),_y(y){

}

Point::Point(const Point &point):_x(point._x),_y(point._y){
	
}

Point::~Point(){

}

void Point::print(){
	std::cout<<"point("<<_x<<","<<_y<<")"<<std::endl;
}

//不用实现，只需声明为私有的就可以
#if 0
void * Point::operator new(size_t size){
	void *point = malloc(size);
	return point;
}

void Point::operator delete(void *p){
	free(p);	
}

#endif

int main(){
	//Point *p1 = new Point(2,4);
	//Point *p3 = new Point[10];
	Point p2(1,2);
	p2.print();
	//p1->print();
	return 0;	
}
