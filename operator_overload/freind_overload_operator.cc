#include <iostream>

class Complex{
	friend Complex operator+(const Complex &,const Complex &);
	friend Complex operator++(Complex &,int);
	friend Complex& operator++(Complex &);
private:
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
	std::cout<<_real;
	if(_imag>0){
		std::cout<<" + "<<_imag<<"i"<<std::endl;
	}else{
		std::cout<<" - "<<_imag<<"i"<<std::endl;
	}
}

Complex operator+(const Complex &c1,const Complex &c2){
	Complex c(c1);
	c._real+=c2._real;
	c._imag+=c2._imag;
	return c;
}

//后置++
Complex operator++(Complex & c,int){
	Complex cc(c);
	++c;
	return cc;
}

//前置++
Complex& operator++(Complex &c){
	++c._real;
	++c._imag;
	return c;	
}

int main(){
	Complex c1(1,2);
	Complex c2(-5,6);
	c1++.print();
	(++c2).print();
	Complex c3 = c1+5;
	c3.print();	
	Complex c4 = 5+c3;
	c4.print();
	return 0;
}
