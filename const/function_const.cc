#include <iostream>

class Point{
private:
	int _x;
	int _y;
public:
	explicit Point(int x=0,int y=0);
	Point(const Point &);
	~Point();
	void print();
	void print() const;
	void setX(int x);
	void doNothing();
	void getX() const;
};

Point::Point(int x,int y):_x(x),_y(y){
	std::cout<<"Point create"<<std::endl;
}

Point::Point(const Point &point):_x(point._x),_y(point._y){
	std::cout<<"Point copy"<<std::endl;
}

//析构函数中能够修该变量
//调用非const函数
Point::~Point(){
	std::cout<<"Point destroy"<<std::endl;
	//printf("%p\n",this);
	this->_y = 30;
	_x = 20;
	setX(90);
}

void Point::print(){
	std::cout<<"_x = "<<_x<<std::endl;
	std::cout<<"_y = "<<_y<<std::endl;
}

//常量对象只能调用常量函数
void Point::print() const{
	std::cout<<"const function"<<std::endl;
	std::cout<<"_x = "<<_x<<std::endl;
	std::cout<<"_y = "<<_y<<std::endl;
	//在const函数中不可以调用非const函数
	//doNothing();
}

void Point::setX(int x){
	_x = x;
}

void Point::getX() const{
	std::cout<<"const getX()"<<std::endl;
}

void Point::doNothing(){
	std::cout<<"doNothing"<<std::endl;
}

int main(){
	Point p1;
	Point p2 = p1;
	p2.setX(100);
	p2.print();	
	const Point p3 = p2;
	p3.print();
	//非const对象可以调用const函数
	p1.getX();
	return 0;
}
