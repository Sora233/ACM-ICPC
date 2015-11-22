#include<stdio.h>
int main(){
	int num,flag;
	for(int i=1;scanf("%d",&num)!=EOF;i++){
		flag=1;
		if(num<1) break;
		else if(num<3) {
			printf("%d: no\n",i);
			continue;
		}
		else if((num%2==0)) {
			printf("%d: no\n",i);
			continue;
		}
		for(int j=5;j<=16000&&num>j&&flag;j+=2)
			if(num!=j&&num%j==0) flag=0;
		printf("%d: %s\n",i,flag?"yes":"no");
	}
}
