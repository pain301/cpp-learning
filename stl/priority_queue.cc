#include <iostream>
#include <queue>
#include <vector>

using std::priority_queue;

int main(){
	int arr[] = {4,8,1,5,9,-8,19,3};
	priority_queue<int,std::vector<int>,std::greater<int> > q;
	int i = 0;
	while(i<8){
		q.push(arr[i++]);
	}
	while(q.size()>0){
		std::cout<<q.top()<<" ";
		q.pop();
	}
	std::cout<<std::endl;
	return 0;
}
