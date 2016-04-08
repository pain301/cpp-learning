#include <iostream>
#include <memory>

int main(){
	double *d = new double(3.14);
	std::auto_ptr<double> auto_double(d);

	std::cout<<"*d = "<<*d<<std::endl;
	std::cout<<"auto_double = "<<*auto_double<<std::endl;
	std::cout<<"auto_double.get() = "<<auto_double.get()<<std::endl;
	
	//复制的时候发生所有权的转移
	std::auto_ptr<double> auto_copy(auto_double);
	std::cout<<"auto_copy = "<<*auto_copy<<std::endl;
	//std::cout<<"auto_double = "<<*auto_double<<std::endl;
	
	char *c = new char('A');
	std::auto_ptr<char> auto_char(c);
	//赋值的时候也会发生所有权的转移
	std::auto_ptr<char> auto_char1 = auto_char;
	std::cout<<*auto_char1<<std::endl;
	//std::cout<<*auto_char<<std::endl;

	int *i = new int(10);
	std::auto_ptr<int> auto_int;
	//只能通过方法改变指针的指向
	auto_int.reset(i);
	std::cout<<"auto_int = "<<*auto_int<<std::endl;

	return 0;
}
