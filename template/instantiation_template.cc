#include <iostream>

template<typename T>
T max(T a,T b){
	return a>b?a:b;
}

template<typename T,int NUM>
T fun(T a){
	return a*NUM;
}

int main(){
	int a=1,b=4;
	double c=3.14,d=5.78;
	//隐式实例化
	std::cout<<max(a,b)<<std::endl;
	//显示实例化
	std::cout<<max<int>(c,d)<<std::endl;
	std::cout<<fun<double,2>(17)<<std::endl;
	return 0;
}
