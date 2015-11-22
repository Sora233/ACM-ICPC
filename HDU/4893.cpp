#include<iostream>
#include<string.h>
#include<stdlib.h>
#define ll __int64 
#define ld I64d
using namespace std; 
ll Fib[30]={0},num[100010]={0};
bool nu[100010]={0};
int abs(int x){
	return x>0?x:-x;
}
int lowbit(int x){
	return x&(-x);
}
void update(int pos,int val){
	while(pos<=100000){
		num[pos]+=val;
		pos+=lowbit(pos);
	}
}
ll getsum(int pos){
	ll ans=0;
	while(pos){
		ans+=num[pos];
		pos-=lowbit(pos);
	}
	return ans;
}
ll getval(int k){
	return getsum(k)-getsum(k-1);
}
void add(int k,int val){
	update(k,val);
	nu[k]=0;
}
void ans(int b,int c){
	printf("%ld\n",getsum(c)-getsum(b));
}
void fib(int l,int r){
	for(int i=l;i<=r;i++){
		if(nu[i]) continue;
		int n=getval(i),pos;
		for(pos=1;;pos++) if(Fib[pos]>n) break;
		if(n) update(i,abs(Fib[pos]-n)>=abs(Fib[pos-1]-n)?Fib[pos-1]-n:Fib[pos]-n);
		else update(i,1);
		nu[i]=1;
	}
}
int main(){
	Fib[0]=0,Fib[1]=Fib[2]=1;
	for(int i=3;i<=27;i++)
	Fib[i]=Fib[i-1]+Fib[i-2];
	int m,n;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(a==1) add(b,c);
			if(a==2) ans(b-1,c);
			if(a==3) fib(b,c);
		}
	}
}
