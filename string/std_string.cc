#include <iostream>
#include <stdio.h>

using std::string;

int main(){
	string s1 = "HelloWorld";
	string s2 = s1;
	string s3 = s2;

	printf("Before changed...\n");

	printf("s1 address :%p\n",s1.c_str());
	printf("s2 address :%p\n",s2.c_str());
	printf("s3 address :%p\n",s3.c_str());

	s1[0] = 'x';
	printf("After changed..\n");
	printf("s1 address :%p\n",s1.c_str());
	printf("s2 address :%p\n",s2.c_str());
	printf("s3 address :%p\n",s3.c_str());
	
	return 0;	
}
