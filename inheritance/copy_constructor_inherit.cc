#include <iostream>
#include <cstring>

class BaseString{
private:
	char *_pstr;
public:
	BaseString();
	BaseString(const char *);
	BaseString(const BaseString &);
	~BaseString();
	BaseString& operator=(const BaseString &);
	void print();
};

BaseString::BaseString(){
	std::cout<<"BaseString()"<<std::endl;
	_pstr = new char[2];
	_pstr[1] = '\0';
}

BaseString::BaseString(const char *pstr){
	std::cout<<"BaseString(const char *)"<<std::endl;
	int len = strlen(pstr);
	_pstr = new char[len+1];
	strcpy(_pstr,pstr);
	_pstr[len] = '\0';	
}

BaseString::BaseString(const BaseString &bs){
	std::cout<<"BaseString(const BaseString &)"<<std::endl;
	int len = strlen(bs._pstr);
	_pstr = new char[len+1];
	strcpy(_pstr,bs._pstr);	
	_pstr[len] = '\0';
}

BaseString::~BaseString(){
	std::cout<<"~BaseString()"<<std::endl;
	if(_pstr!=NULL){
		delete []_pstr;
		_pstr = NULL;
	}
}

BaseString& BaseString::operator=(const BaseString &bs){
	std::cout<<"operator=(const BaseString &)"<<std::endl;
	if(this!=&bs){
		delete[] _pstr;
		int len = strlen(bs._pstr);
		_pstr = new char[len+1];
		strcpy(_pstr,bs._pstr);
		_pstr[len] = '\0';
	}
	return *this;
}

void BaseString::print(){
	std::cout<<_pstr<<std::endl;
}

class DerivedString:public BaseString{
public:
	DerivedString(const char *pstr,int val = 0);
	DerivedString(const DerivedString &);
	~DerivedString();
	DerivedString& operator=(const DerivedString &);
	void print();
private:
	int _val;
};

DerivedString::DerivedString(const char *pstr,int val):BaseString(pstr),_val(val){
	std::cout<<"DerivedSttring(const char *)"<<std::endl;
}

//当派生类定义了拷贝构造函数之后，必须显示调用基类的拷贝构造函数，否则基类成员不进行拷贝
DerivedString::DerivedString(const DerivedString &ds):_val(ds._val),BaseString(ds){
	std::cout<<"DerivedString(const DerivedString &)"<<std::endl;
}

DerivedString::~DerivedString(){
	std::cout<<"~DerivedString()"<<std::endl;
}

void DerivedString::print(){
	BaseString::print();
	std::cout<<"_val = "<<_val<<std::endl;
}

//当派生类重载了赋值运算符，必须显示调用基类的赋值运算函数，否则基类成员不进行赋值
DerivedString& DerivedString::operator=(const DerivedString &ds){
	std::cout<<"operator=(const DerivedString &)"<<std::endl;
	BaseString::operator=(ds);
	_val = ds._val;
	return *this;
}

int main(){
	DerivedString d1("pain",10);
	DerivedString d2(d1);	
	DerivedString d3("hello world",20);
	d1.print();
	d2.print();
	d3.print();
	d1 = d3;
	d1.print();
	return 0;
}
