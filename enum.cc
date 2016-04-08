#include <iostream>

enum Priority{
	FATAL = 100,
	ERROR,
	WARN,
	DEBUG,
	INFO
};

int main(){
	std::cout<<"FATAL:"<<FATAL<<std::endl;
	std::cout<<"ERROR:"<<ERROR<<std::endl;
	Priority p = FATAL;
	std::cout<<"Priority:"<<p<<std::endl;
	return 0;
}
