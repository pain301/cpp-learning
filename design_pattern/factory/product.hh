#ifndef _PRODUCT_H_
#define _PRODUCT_H_

class Product{
public:
	Product();
	virtual ~Product();
	virtual void operate() = 0;
};

class ProductA:public Product{
public:
	ProductA();
	~ProductA();
	void operate();
};

class ProductB:public Product{
public:
	ProductB();
	~ProductB();
	void operate();
};
#endif
