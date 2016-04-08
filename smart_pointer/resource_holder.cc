#include <iostream>

class Resource{};

class ResHolder{
private:
	Resource *p1;
	Resource *p2;
public:
	ResHolder();
	ResHolder(const ResHolder &resHolder);
	ResHolder& operator=(const ResHolder &resHolder);	
	~ResHolder();
};

ResHolder::ResHolder():p1(new Resource()),p2(new Resource()){

}

ResHolder::ResHolder(const ResHolder &resHolder):
		p1(new Resource(*resHolder.p1)),p2(new Resource(*resHolder.p2)){

}

ResHolder& ResHolder::operator=(const ResHolder &resHolder){
	if(this==&resHolder)
		return *this;
	else{
		*p1 = *resHolder.p1;
		*p2 = *resHolder.p2;
		return *this;
	}	
}

ResHolder::~ResHolder(){
	std::cout<<"~ResHolder()"<<std::endl;
	delete p1;
	p1 = NULL;
	delete p2;
	p2 = NULL;
}

int main(){
	ResHolder resHolder;	
	return 0;
}
