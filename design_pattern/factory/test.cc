#include "product.hh"
#include "factory.hh"
#include <iostream>

int main(){

	Factory *fa = new FactoryA();
	Product *p = fa->produce();
	p->operate();
	if(p!=NULL){
		delete p;
		p = NULL;
	}

	if(fa!=NULL){
		delete fa;
		fa = NULL;
	}

	std::cout<<std::endl;
	
	Factory *fb = new FactoryB();
	p = fb->produce();
	p->operate();

	if(p!=NULL){
		delete p;
		p = NULL;
	}
	
	if(fb!=NULL){
		delete fb;
		fb = NULL;
	}

	return 0;
}
