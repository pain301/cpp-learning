#include <iostream>
#include <vector>
#include <algorithm> //for_each
#include <functional> //less<>

using std::vector;

void print(const vector<int>::value_type &v){
	std::cout<<v<<" ";
}

int main(){
	int arr[] = {1,2,3,4};
	vector<int> vc(arr,arr+4);
	for_each(vc.begin(),vc.end(),print);
	std::cout<<std::endl;
	
	std::less<int> lt;
	//逆转一元断言
	replace_if(vc.begin(),vc.end(),not1(bind2nd(lt,3)),10);
	for_each(vc.begin(),vc.end(),print);
	std::cout<<std::endl;	
	return 0;
}
