#include <iostream>
#include <map>
#include <string>

using std::string;
using std::pair;
using std::map;
using std::multimap;

void displayMap(const map<const int,string> &mapping){
	map<const int,string>::const_iterator iter = mapping.begin();
	while(iter!=mapping.end()){
		std::cout<<iter->first<<":"<<iter->second<<" ";
		++iter;
	}
	std::cout<<std::endl;
}

void displayMultiMap(const multimap<const int,string> &mapping){
	multimap<const int,string>::const_iterator iter = mapping.begin();
	while(iter!=mapping.end()){
		std::cout<<iter->first<<":"<<iter->second<<" ";
		++iter;
	}
	std::cout<<std::endl;
}

int main(){
	pair<const int,string> t(1,"hello pain");
	std::cout<<t.first<<" "<<t.second<<std::endl;
	pair<const int,string> parr[] = {pair<const int,string>(-3,"Lebron"),
					 pair<const int,string>(-10,"Kd"),
					 pair<const int,string>(-5,"kevin"),
					 pair<const int,string>(1,"hello"),
					 pair<const int,string>(-5,"fukc you"),
					 pair<const int,string>(3,"pick")};
	map<const int,string> mapping(parr,parr+6);
	displayMap(mapping);

	multimap<const int,string> mulmap(parr,parr+6);
	displayMultiMap(mulmap);
	return 0;
}
