#include <iostream>
#include <iterator>
#include <vector>

using std::vector;

int main(){
	int arr[] = {1,2,3,4,5};
	vector<int> vc(arr,arr+5);
	std::ostream_iterator<int,char> osi(std::cout," ");
	copy(vc.rbegin(),vc.rend(),osi);
	std::cout<<std::endl;	
	return 0;
}
