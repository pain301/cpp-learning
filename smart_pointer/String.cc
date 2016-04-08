#include <string.h>
#include <iostream>
#include <vector>

class String
{
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	String(String && rhs);
	String &operator=(String && rhs);
	String &operator=(const String & rhs);
	~String();

private:
	char *pstr_;
};

String::String()
{
	std::cout << "String()" << std::endl;
	pstr_ = new char[1];
}

String::String(const char * pstr)
{
	std::cout << "String(const char *pstr)" << std::endl;
	pstr_ = new char[strlen(pstr) + 1];
	strcpy(pstr_, pstr);
}

String::String(const String & rhs)
{
	std::cout << "String(const String &rhs)" << std::endl;
	pstr_ = new char[strlen(rhs.pstr_) + 1];
	strcpy(pstr_, rhs.pstr_);
}

String & String::operator=(const String & rhs)
{
	std::cout <<"String & operator=(const String & rhs)" 
			  << std::endl;
	if(this != &rhs)
	{
		delete [] pstr_;
		pstr_ = new char [strlen(rhs.pstr_) + 1];
		strcpy(pstr_, rhs.pstr_);
	}
	return *this;
}

#if 1
String::String(String && rhs)
{
	std::cout << "String(String && rhs)" << std::endl;
	pstr_ = rhs.pstr_;
	rhs.pstr_ = NULL;
}
String & String::operator=(String && rhs)
{
	std::cout << "String & operator=(String && rhs)" << std::endl;
	if(this != &rhs)
	{
		delete []pstr_;
		pstr_ = rhs.pstr_;
		rhs.pstr_ = NULL;
	}
	return *this;
}
#endif

String::~String()
{
	std::cout << "~String()" << std::endl;
	delete []pstr_;
}

int main(void)
{
	std::vector<String> vecStr;
	vecStr.push_back("hello");
	//String s1 = "hello";
	return 0;	
}
