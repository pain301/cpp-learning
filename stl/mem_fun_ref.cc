#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

using std::vector;

class Number{
private:
	int _val;
public:
	Number(int val = 0);
	void display();
	bool isPrime();
};

Number::Number(int val):_val(val){

}

void Number::display(){
	std::cout<<_val<<" ";
}

bool Number::isPrime(){
	int i = 2;
	if(_val==2)	
		return true;
	int tmp = sqrt(_val)+1;
	for(;i<tmp;++i){
		if(_val%i==0)	
			return false;
	}
	return true;
}

int main(){
	vector<Number> vc;
	int i = 2;
	while(i<25){
		vc.push_back(Number(i++));
	}
	for_each(vc.begin(),vc.end(),std::mem_fun_ref(&Number::display));
	std::cout<<std::endl;
	vector<Number>::iterator iter = remove_if(vc.begin(),vc.end(),std::mem_fun_ref(&Number::isPrime));
	vc.erase(iter,vc.end());
	for_each(vc.begin(),vc.end(),std::mem_fun_ref(&Number::display));	
	std::cout<<std::endl;
	return 0;
}
