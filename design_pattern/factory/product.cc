#include "product.hh"
#include <iostream>

Product::Product(){
	std::cout<<"Product()"<<std::endl;
}

Product::~Product(){
	std::cout<<"~Product()"<<std::endl;
}

ProductA::ProductA(){
	std::cout<<"ProductA()"<<std::endl;
}

ProductA::~ProductA(){
	std::cout<<"~ProductA()"<<std::endl;
}

void ProductA::operate(){
	std::cout<<"operation A"<<std::endl;
}

ProductB::ProductB(){
	std::cout<<"ProductB()"<<std::endl;
}

ProductB::~ProductB(){
	std::cout<<"~ProductB()"<<std::endl;
}

void ProductB::operate(){
	std::cout<<"operation B"<<std::endl;
}
