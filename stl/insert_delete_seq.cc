#include <vector>
#include <list>
#include <deque>
#include <string>
#include <iostream>

using std::vector;
using std::list;
using std::deque;
using std::string;

void displayVector(const vector<int> &vc){
	vector<int>::const_iterator iter = vc.begin();
	while(iter!=vc.end()){
		std::cout<<*iter++<<" ";
	}
	std::cout<<std::endl;
}

void displayDeque(const deque<double> &dq){
	deque<double>::const_iterator iter = dq.begin();
	while(iter!=dq.end()){
		std::cout<<*iter++<<std::endl;
	}
}

void displayList(const list<int> &ls){
	list<int>::const_iterator iter = ls.begin();
	while(iter!=ls.end()){
		std::cout<<*iter++<<std::endl;
	}
}

void testPush_back(vector<int> &vc){
	int i = 0;
	while(i<10){
		vc.push_back(i++);
		std::cout<<"vc capacity is "<<vc.capacity()<<std::endl;
	}
}

void testPush_front(deque<double> &dq){
	double d = 3.14;
	while(d<10){
		dq.push_front(d++);
	}
}

void testFront_back(list<string> &ls){
	string str[] = {"hello","pain","world"};
	std::cout<<"list front "<<ls.front()<<std::endl;
	std::cout<<"list back "<<ls.back()<<std::endl;

}

void testInsert(){
	int arr[] = {1,2,3,4,5};
	vector<int> vc(arr,arr+5);
	displayVector(vc);		
	vector<int>::iterator it = vc.end();
	//返回的迭代器指向被插入的元素
	//在it之前插入元素6
	it = vc.insert(it,6);
	displayVector(vc);
	vc.insert(it,5,7);
	displayVector(vc);
	int array[] = {-1,-2,-3,-4,-5};
	//迭代器失效
	//vc.insert(it,array,array+2);	
	displayVector(vc);
}

int main(){
	int arr[] = {1,4,9,16,25,36,49};
	vector<int> vc(arr,arr+5);
	//displayList(ls);		
	vector<int>::iterator iter = vc.begin();
	++iter;
	//删除迭代器所指向的元素，并且返回指向下一个元素的迭代器
	iter = vc.erase(iter);
	//displayList(ls);
	//删除从[iter,ls.end())之间的元素
	vc.erase(++iter,vc.end());
	displayVector(vc);
	//删除所有元素
	vc.clear();
	std::cout<<"ls size is "<<vc.size()<<std::endl;
	return 0;
}
