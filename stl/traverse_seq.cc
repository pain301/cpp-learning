#include <vector>
#include <queue>
#include <list>
#include <string>
#include <iostream>

using std::vector;
using std::deque;
using std::list;
using std::string;

int main(){

	vector<string> vc(10,"pain");
	vector<string>::iterator it = vc.begin();
	while(it!=vc.end()){
		std::cout<<*it<<std::endl;
		++it;
	}
	std::cout<<std::endl;

	int arr[] = {1,2,3,4,5,6};
	deque<int> q(arr,arr+6);	
	int i = 0;
	while(i<q.size()){
		std::cout<<q[i++]<<std::endl;
	}
	
	list<double> l(5,3.14);	
	list<double> l2(7,8.88);
	list<double>::iterator lit = l.begin();
	while(lit!=l.end()){
		(*lit)+=3;
		std::cout<<*lit++<<std::endl;
	}
	std::cout<<std::endl;

	l.swap(l2);
	lit = l.begin();
	while(lit!=l.end()){
		std::cout<<*lit++<<std::endl;
	}
	
	std::cout<<"l capacity is "<<l.size()<<std::endl;
	std::cout<<"l2 capacity is "<<l2.size()<<std::endl;

	return 0;
}
