#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

int main(){
	//指定stack用vector实现
	stack<int,vector<int> > s;
	int i = -1;
	while(i>-6)
		s.push(i--);
	while(s.size()>0){
		std::cout<<s.top()<<" ";
		s.pop();
	}
	std::cout<<std::endl;
	return 0;
}
