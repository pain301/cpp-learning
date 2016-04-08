#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

void print(const vector<int>::value_type &v){
	std::cout<<v<<" ";
}

int main(){
	int arr[] = {1,3,5,8,4,2,5,7,1,5};
	vector<int> vc(arr,arr+10);
	for_each(vc.begin(),vc.end(),print);
	std::cout<<std::endl;
	//并没有真正的删除元素
	vector<int>::iterator it = remove(vc.begin(),vc.end(),5);
	for_each(vc.begin(),vc.end(),print);
	std::cout<<std::endl;
	vc.erase(it,vc.end());
	for_each(vc.begin(),vc.end(),print);
	std::cout<<std::endl;
	return 0;
}
