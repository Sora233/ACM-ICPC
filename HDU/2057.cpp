#include<stdio.h>
int main(){
	long long int a,b;
	char A,B;
	while(scanf("%c%LLX %c%LLX%*c",&A,&a,&B,&b)!=EOF){
		if(A=='+'&&B=='+'){
			printf("%LLX\n",a+b);
		}
		if(A=='+'&&B=='-'){
			if(a>=b) printf("%LLX\n",a-b);
			else if(a<b) printf("-%LLX",b-a);
		}
		if(A=='-'&&B=='+'){
			if(a<=b)printf("%LLX\n",b-a);
			else if(a>b) printf("%LLX\n",a-b);
		}
		if(A=='-'&&B=='-') printf("-%LLX",a+b);
	}
}
