#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "product.hh"

class Factory{
public:
	Factory();
	virtual ~Factory();
	virtual Product* produce() = 0;
};

class FactoryA:public Factory{
public:
	FactoryA();
	~FactoryA();
	virtual Product* produce();
};

class FactoryB:public Factory{
public:
	FactoryB();
	~FactoryB();
	virtual Product* produce();
};
#endif
