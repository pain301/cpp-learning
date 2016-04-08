#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using std::vector;

void display(const vector<int> &vc){
	vector<int>::const_iterator it = vc.begin();
	while(it!=vc.end()){
		std::cout<<*it++<<" ";
	}
	std::cout<<std::endl;
}

void print(vector<int>::value_type v){
	std::cout<<v<<" ";
}

int main(){
	int arr[] = {1,2,3,4,5,6};
	vector<int> vc(arr,arr+6);
	std::less<int> lt;
	//将小于3的元素换成100
	replace_if(vc.begin(),vc.end(),bind2nd(lt,3),100);
	display(vc);
	//将大于10的元素换成-100
	replace_if(vc.begin(),vc.end(),bind1st(lt,10),-100);
	for_each(vc.begin(),vc.end(),print);
	return 0;
}
