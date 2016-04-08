#include <iostream>

class Complex{
private:
	int _real;
	int _imag;
public:
	Complex(int real = 0,int imag = 0);
	Complex(const Complex &);

	//只能0或者1个参数
	//+操作符以普通函数重载更符合逻辑
	Complex operator+(const Complex &);
	Complex & operator+=(const Complex &);
	Complex & operator-=(const Complex &);
	//取反-
	Complex operator-();
	//前置++
	Complex& operator++();
	//后置++
	Complex operator++(int);
	void print();
};

Complex::Complex(int real,int imag):_real(real),_imag(imag){

}

Complex::Complex(const Complex &c):_real(c._real),_imag(c._imag){

}

//优先被采用
Complex Complex::operator+(const Complex &c){
	std::cout<<"Complex::operator+"<<std::endl;
	Complex cc(c);
	cc._real+=_real;
	cc._imag+=_imag;
	return cc;
}
#if 1
Complex operator+(const Complex &c1,const Complex &c2){
	std::cout<<"operator+"<<std::endl;
	Complex c(c1);
	c+=c2;
	return c;
}
#endif

Complex operator-(const Complex &c1,const Complex &c2){
	Complex c(c1);
	c-=c2;
	return c;
}

Complex & Complex::operator+=(const Complex &c){
	_real+=c._real;
	_imag+=c._imag;
	return *this;
}

Complex & Complex::operator-=(const Complex &c){
	_real-=c._real;
	_imag-=c._imag;
	return *this;
}

Complex Complex::operator-(){
	return Complex(-_real,-_imag);
}

Complex& Complex::operator++(){
	++_real;
	++_imag;
	return *this;
}

Complex Complex::operator++(int){
	Complex c(*this);
	++(*this);
	return c;
}

void Complex::print(){
	std::cout<<_real;
	if(_imag>0){
		std::cout<<" + "<<_imag<<"i"<<std::endl;
	}else{
		std::cout<<" - "<<-_imag<<"i"<<std::endl;
	}
}

int main(){
	Complex c1(1,2);
	Complex c2(-2,-5);
	c1.print();
	c2.print();
	Complex c3 = c1++;
	c3.print();
	c3+=c1;
	c3.print();
	//调用Complex::operator+(const Complex &);
	Complex c4 = c2+5;
	//调用operator+(const Complex &,const Complex &);
	Complex c5 = 5+ c4;
	c4.print();
	return 0;
}
