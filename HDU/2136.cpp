#include<stdio.h>
#include<string.h>
int prime[1000001]={0};
int main(){
	int t=1,n;
	for(int i=2;i<1000000;i++)
	if(prime[i]==0){
		for(int j=i;j<1000000;j+=i)
		prime[j]=t;
		t++;
	}
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",prime[n]);
	}
}
