#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::vector;

int main(){
	int arr[] = {-1,-5,6,2,4,6};
	vector<int> vc(arr,arr+6);
	std::ostream_iterator<int,char> osi(std::cout,"@");
	copy(vc.begin(),vc.end(),osi);
	std::cout<<std::endl;
}
