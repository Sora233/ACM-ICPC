#include<cstdio>
#define MAXN 100000
long long int a[MAXN];
main()
{
	int n,i,j=1;
	for(i=1;i<MAXN;i++,j+=2)
	a[i]+=a[i-1]+j*j;
	while(scanf("%d",&n)!=EOF)
		printf("%lld\n",a[(n+1)/2]);
}
