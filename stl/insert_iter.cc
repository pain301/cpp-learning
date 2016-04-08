#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::vector;
using std::list;

void print(const list<int>::value_type &v){
	std::cout<<v<<" ";
}

int main(){
	int arr[] = {1,2,3,4};
	vector<int> vc(arr,arr+4);
	list<int> ls;

	//尾部插入
	copy(vc.begin(),vc.end(),std::back_insert_iterator<list<int> >(ls));
	for_each(ls.begin(),ls.end(),print);
	std::cout<<std::endl;

	//头部插入
	ls.clear();
	copy(vc.begin(),vc.end(),std::front_insert_iterator<list<int> >(ls));
	for_each(ls.begin(),ls.end(),print);
	std::cout<<std::endl;

	//指定位置插入
	ls.clear();
	ls.push_back(100);
	ls.push_back(200);
	copy(vc.begin(),vc.end(),std::insert_iterator<list<int> >(ls,++ls.begin()));	
	for_each(ls.begin(),ls.end(),print);
	std::cout<<std::endl;

	return 0;
}
