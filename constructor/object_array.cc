#include <iostream>

class Point{
private:
	int _x;
	int _y;
public:
	Point(int x,int y);
	Point();
	~Point();
};

Point::Point(int x,int y):_x(x),_y(y){
	std::cout<<"Point(int x,int y)"<<std::endl;
}

Point::Point():_x(0),_y(0){
	std::cout<<"Point()"<<std::endl;	
}

Point::~Point(){
	std::cout<<"Point destroy"<<std::endl;
}

int main(){
	Point array1[] = {Point(1,2),Point(2,3)};
	//后两个调用无参构造函数
	Point array2[3] = {Point(2,3)};
	return 0;
}
