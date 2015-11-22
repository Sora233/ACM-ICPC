#include<cstdio>
main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--){
		i=1;
		scanf("%d",&n);
		while(n!=0){
			if(n-i<=0) break;
			n-=i;
			i++;
		}
		printf("%d\n",n);
	}
}
