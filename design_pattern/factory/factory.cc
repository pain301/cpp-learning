#include "factory.hh"
#include <iostream>

Factory::Factory(){
	std::cout<<"Factory()"<<std::endl;
}

Factory::~Factory(){
	std::cout<<"~Factory()"<<std::endl;
}

FactoryA::FactoryA(){
	std::cout<<"FactoryA()"<<std::endl;
}

FactoryA::~FactoryA(){
	std::cout<<"~FactoryA()"<<std::endl;
}

Product* FactoryA::produce(){
	return new ProductA();
}

FactoryB::FactoryB(){
	std::cout<<"FactoryB()"<<std::endl;
}

FactoryB::~FactoryB(){
	std::cout<<"~FactoryB()"<<std::endl;
}

Product* FactoryB::produce(){
	return new ProductB();
}
