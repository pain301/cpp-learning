#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class String{
	friend ostream& operator<<(ostream &os,const String &s);
private:
	class CharProxy{
		public:
			CharProxy(String &,size_t );	

			//改变字符
			CharProxy & operator=(char );
			//不改变字符
			operator char() const;
		private:
			String &outer;
			size_t index;
	};
private:
	char *_pstr;
public:
	String();
	String(const char *pstr);
	String(const String &);
	String& operator=(const String &);
	CharProxy operator[](int);
	~String();
	void printAddress();
	size_t getSize() const;
};

String::String(){
	_pstr = new char[2];
	_pstr[1] = 1;
}

String::String(const char *pstr){
	if(pstr==NULL){
		_pstr = new char[2];
		_pstr[1] = 1;
		return ;
	}
	int len = strlen(pstr);
	_pstr = new char[len+2];
	_pstr[len+1] = 1;
	strcpy(_pstr,pstr);
}

String::String(const String &str){
	int len = strlen(str._pstr);
	_pstr = str._pstr;
	++_pstr[len+1];
}

String& String::operator=(const String &str){
	if(this!=&str){
		int len = strlen(_pstr);
		if(--_pstr[len+1]==0){
			delete []_pstr;
		}
		_pstr = str._pstr;
		len = strlen(_pstr);
		++_pstr[len+1];
	}
	return *this;
}

String::~String(){
	std::cout<<"~String()"<<std::endl;
	int len = strlen(_pstr);
	if(--_pstr[len+1]==0){
		delete []_pstr;
		std::cout<<"delete a string"<<std::endl;
	}
}

void String::printAddress(){
	printf("address %p\n",_pstr);
}

String::CharProxy String::operator[](int index){
	return CharProxy(*this,index);
}

size_t String::getSize() const{
	return strlen(_pstr);
}

ostream& operator<<(ostream &os,const String &s){
	os<<s._pstr;
	return os;
}

/*************CharProxy*******************/

String::CharProxy::CharProxy(String &str,size_t size):outer(str),index(size){

}

String::CharProxy& String::CharProxy::operator=(char c){
	int len = outer.getSize();
	if(index>=0||index<len){
		if(outer._pstr[len+1]>1){
			char *tmp = new char[len+2];
			strcpy(tmp,outer._pstr);
			--outer._pstr[len+1];
			tmp[len+1] = 1;
			outer._pstr = tmp;	
		}
		outer._pstr[index] = c;
	}
	return *this;
}

String::CharProxy::operator char() const{
	static char nullchar = '\0';
	int len = outer.getSize();
	if(index>=0&&index<len)
		return outer._pstr[index];
	else
		return nullchar;
}

int main(){
	String s1 = "hello world";
	String s2 = s1;//"pain main";
	String s3 = s2;
	
	s1.printAddress();
	s2.printAddress();
	s3.printAddress();


	std::cout<<"s1[0] = "<<s1[0]<<std::endl;
	std::cout<<"s2[0] = "<<s2[0]<<std::endl;
	std::cout<<"s3[0] = "<<s3[0]<<std::endl;

	std::cout<<std::endl;

	std::cout<<"s1 = "<<s1<<std::endl;
	std::cout<<"s2 = "<<s2<<std::endl;
	std::cout<<"s3 = "<<s3<<std::endl;
	
	s1.printAddress();
	s2.printAddress();
	s3.printAddress();
}
