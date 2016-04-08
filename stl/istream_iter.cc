#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::vector;

int main(){
	vector<int> vc;
	std::istream_iterator<int,char> isi(std::cin);
	//将输入流插入到vc中
	copy(isi,std::istream_iterator<int,char>(),back_inserter(vc));
	vector<int>::iterator it = vc.begin();
	while(it!=vc.end()){
		std::cout<<*it++<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
