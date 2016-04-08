#include <iostream>

int max(int a,int b){
	std::cout<<"max(int ,int)"<<std::endl;
	return a>b?a:b;
}

template<typename T>
T max(T a,T b){
	std::cout<<"max(T,T)"<<std::endl;
	return a>b?a:b;
}

template<typename T>
T max(T a,T b,T c){
	std::cout<<"max(T,T,T)"<<std::endl;
	return a+b+c;
}

template<typename T>
T max(T* arr,int n){
	T max = arr[0];
	int i = 1;
	for(;i<n;++i){
		if(arr[i]>max)
			max = arr[i];
	}
	std::cout<<"max(T[],int)"<<std::endl;
	return max;
}

int main(){
	std::cout<<max<double>(1,2,3.23)<<std::endl;
	double arr[5] = {3.14,5.28,6.28,12.31,3.14};
	std::cout<<max(arr,sizeof(arr)/sizeof(arr[0]))<<std::endl;
	return 0;
}
