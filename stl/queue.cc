#include <iostream>
#include <queue>

using std::queue;

int main(){
	queue<int> q;
	int i = 0;
	while(i<6){
		q.push(i++);
	}
	while(q.size()>0){
		std::cout<<q.front()<<" ";
		q.pop();
	}
	std::cout<<std::endl;
	return 0;
}
