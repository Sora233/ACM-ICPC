#include<stdio.h>
int quickpow(int n,int m){
	int r=1;
	while(m>0){
	   if(m&1) r=(r*n)%10;
	   n=(n*n)%10;
	   m>>=1;
	}
	return r;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,r;
		scanf("%d",&n);
		r=quickpow(n%10,n);
		printf("%d\n",r);
	}
}
