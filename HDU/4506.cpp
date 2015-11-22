#include<stdio.h>
#define LL long long int
const LL mod=1000000007;
LL powmod(LL k,LL t){
	LL ans=1;
	while(t){
		if(t&1) ans=(ans*k)%mod;
		k=(k*k)%mod;
		t>>=1;
	}
	return ans%mod;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL n,t,k,a[10005];
		scanf("%lld%lld%lld",&n,&t,&k);
		k=powmod(k,t);
		for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		a[i]=((a[i]%mod)*k)%mod;
	    }
	    if(t) t%=n;
	    for(int i=n-t,co=0;co<n;++co,++i){
	    	if(i==n) i=0;
	    	if(!co) printf("%lld",a[i]);
	    	else printf(" %lld",a[i]);
       }
	    printf("\n");
	}
}
