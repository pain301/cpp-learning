#include <iostream>

//普通类模板
template<typename T1,typename T2>
class Convert1{
public:
	T1 fun(T2 data);
};

template<typename T1,typename T2>
T1 Convert1<T1,T2>::fun(T2 data){
	return T1(data);
}

//嵌套类模板
template<typename T1>
class Convert2{
public:
	template<typename T2>
	T1 fun(T2 data);
};

template<typename T1>
template<typename T2>
T1 Convert2<T1>::fun(T2 data){
	return T1(data);
}

int main(){
	Convert1<int,double> c1;
	std::cout<<c1.fun(3.14)<<std::endl;
	Convert1<char,int>c2;
	std::cout<<c2.fun(65)<<std::endl;

	Convert2<int>c3;
	std::cout<<c3.fun(4.55)<<std::endl;
	return 0;
}
