#include <stdio.h>
int fibS(int x,int y,int z){int a=y+z;if(a<=x){printf("%d %d \n",y,a);return fibS(x,a,y);}return 1;}

void fib(int x){fibS(x,1,0);}

int main(){
	int x;
	scanf("%d",&x);
	fib(x);
	return x;
}
