#include <iostream>
using namespace std;

class Complex{
	//使用引用，ostream的拷贝构造函数为私有
	//不能使用成员函数重载，因为第一个参数为ostream对象
	//ostream形式参数不能用const修饰，因为os随着输出内容会发生变化
	friend ostream& operator<<(ostream &os,const Complex &c);
	friend istream& operator>>(istream &is,Complex &c);
private:
	int _real;
	int _imag;
public:
	Complex(int real=0,int imag=0);
	Complex(const Complex &);
	void print() const;
};

Complex::Complex(int real,int imag):_real(real),_imag(imag){

}

Complex::Complex(const Complex &c):_real(c._real),_imag(c._imag){

}

void Complex::print() const{
	std::cout<<_real;
	if(_imag>0){
		std::cout<<" + "<<_imag<<"i"<<std::endl;
	}else{
		std::cout<<" - "<<-_imag<<"i"<<std::endl;
	}
}

ostream& operator<<(ostream &os,const Complex &c){
	os<<c._real;
	if(c._imag>0){
		os<<" + "<<c._imag<<"i";
	}else{
		os<<" - "<<-c._imag<<"i";
	}
	return os;
}

istream& operator>>(istream &is,Complex &c){
	is>>c._real>>c._imag;
}

int main(){
	Complex c1(1,3);
	Complex c2(-3,-6);
	std::cout<<c1<<std::endl;
	std::cout<<c2<<std::endl;
	Complex c3;
	std::cin>>c3;
	std::cout<<c3<<std::endl;
	return 0;
}
