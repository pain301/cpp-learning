#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;
using std::pair;

void display(const map<int,string> &mp){
	map<int,string>::const_iterator iter = mp.begin();
	while(iter!=mp.end()){
		std::cout<<iter->first<<":"<<iter->second<<std::endl;
		++iter;
	}
}

int main(){
	pair<int,string> pairArr[] = {pair<int,string>(1,"china"),pair<int,string>(2,"hello"),pair<int,string>(3,"pain")};
	map<int,string> mp(pairArr,pairArr+3);
	display(mp);
	std::cout<<"---------------"<<std::endl;

	map<int,string>::size_type st = mp.erase(1);
	display(mp);
	std::cout<<"delete num is "<<st<<std::endl;
	return 0;
}
