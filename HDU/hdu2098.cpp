#include<stdio.h>
int prime[10005]={2,3,5};
int count=3;
bool isprime(int num){
	for(int j=0;prime[j]*prime[j]<=num;j++) if(!(num%prime[j])) return 0;
	return 1;
}
int main(){
	for(int i=1;6*i<=10005;i++){
		if(isprime(6*i+1)) prime[count++]=6*i+1;
		if(isprime(6*i+5)) prime[count++]=6*i+5;
	}
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int co=0;
		for(int i=0;prime[i]<n;i++)
		    for(int j=0;prime[j]<prime[i];j++)
		    {
		    	if(i==j) continue;
		    	if(prime[i]+prime[j]==n) co++;
		    }
		printf("%d\n",co);
	}
}
