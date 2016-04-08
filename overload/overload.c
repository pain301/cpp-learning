#include <stdio.h>

//C语音不支持函数重载
int add(int a,int b){
	return a+b;
}

double add(double a,double b){
	return a+b;
}

int main(){
	printf("add(int,int) = %d\n",add(2,3));
	printf("add(double,double) = %lf\n",add(3.12,4.48));
	return 0;
}
