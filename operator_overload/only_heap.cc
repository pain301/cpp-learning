#include <iostream>
#include <stdlib.h>

class Point{
private:
	int _x;
	int _y;
private:
	~Point();
public:
	Point(int x=0,int y=0);
	//void * operator new(size_t size);
	//void operator delete(void *);
	void destroy();
	void print();
};

Point::Point(int x,int y):_x(x),_y(y){

}

Point::~Point(){

}

void Point::destroy(){
	delete this;
}

void Point::print(){
	std::cout<<"Point("<<_x<<","<<_y<<")"<<std::endl;
}

#if 0
void * Point::operator new(size_t size){
	void * p = malloc(size);	
	return p;
}

void Point::operator delete(void * p){
	free(p);
}
#endif

int main(){
	Point *p = new Point(1,2);
	p->print();
	//delete p;
	p->destroy();
	//Point p1(3,5);
	return 0;
}
