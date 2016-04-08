#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

void print(vector<int>::value_type v){
	std::cout<<v<<" ";
}

int main(){
	vector<int> vc{1,2,3,4,5};
	for_each(vc.begin(),vc.end(),print);
	std::cout<<std::endl;
	return 0;
}
