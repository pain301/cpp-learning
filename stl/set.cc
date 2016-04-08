#include <iostream>
#include <set>

using std::set;
using std::multiset;
using std::ostream;

class Point{
	friend bool operator>(const Point &p1,const Point &p2);
	friend ostream& operator<<(ostream &os,const Point &p);
private:
	int _x;
	int _y;
public:
	Point(int x=0,int y=0);
};

Point::Point(int x,int y):_x(x),_y(y){

}

bool operator>(const Point &p1,const Point &p2){
	return (p1._x*p1._x+p1._y*p1._y)>(p2._x*p2._x+p2._y*p2._y);
}

ostream& operator<<(ostream &os,const Point &p){
	os<<"("<<p._x<<","<<p._y<<")";
	return os;
}

void displaySet(const set<int,std::greater<int> > &s){
	set<int>::iterator iter = s.begin();
	while(iter!=s.end()){
		std::cout<<*iter++<<" ";
	}
	std::cout<<std::endl;
}

void displayMultiset(const multiset<int,std::greater<int> > &s){
	multiset<int>::iterator iter = s.begin();
	while(iter!=s.end()){
		std::cout<<*iter++<<" ";
	}
	std::cout<<std::endl;
}

void displayPoint(const set<Point,std::greater<Point> > &s){
	set<Point,std::greater<Point> >::iterator iter = s.begin();
	while(iter!=s.end()){
		std::cout<<*iter++<<" ";
	}
	std::cout<<std::endl;
}

int main(){
	int arr[] = {-1,-2,-3,-4,-5,-6,-3,-4,-5};
	set<int,std::greater<int> > set1(arr,arr+9);
	displaySet(set1);
	std::cout<<"set size is "<<set1.size()<<std::endl;

	multiset<int,std::greater<int> > set2(arr,arr+9);
	displayMultiset(set2);

	Point pointArr[6] = {Point(9,2),Point(3,4),Point(-5,5),Point(7,1),Point(3,5)};
	set<Point,std::greater<Point> > pointSet(pointArr,pointArr+6);
	displayPoint(pointSet);	

	return 0;	
}
