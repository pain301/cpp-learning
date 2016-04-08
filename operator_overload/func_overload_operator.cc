#include <iostream>

class Complex{
//private:
public:
	int _real;
	int _imag;
public:
	Complex(int real = 0,int imag = 0);
	Complex(const Complex &);
	void print();
};

Complex::Complex(int real,int imag):_real(real),_imag(imag){

}

Complex::Complex(const Complex &c):_real(c._real),_imag(c._imag){

}

void Complex::print(){
	std::cout<<_real<<" ";
	if(_imag>0){
		std::cout<<"+ "<<_imag<<"i"<<std::endl;
	}else{
		std::cout<<"- "<<-_imag<<"i"<<std::endl;
	}
}

//普通函数重载+运算符
//需要类成员变量为public
Complex operator+(const Complex &c1,const Complex &c2){
	Complex c(c1);
	c._real+=c2._real;
	c._imag+=c2._imag;
	return c;
}

int main(){
	Complex c1(1,2);
	Complex c2(3,-4);
	c1.print();
	c2.print();
	Complex c3 = c1+c2;
	c3.print();
	return 0;
}
