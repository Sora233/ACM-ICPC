#include<cstdio>
long long int fact(int n){
	return n==0?1:fact(n-1)*n;
}
main(){
	int n;
	int a[50]={0},sum=1,i;
	for(i=1;i<=40;i++){
			sum*=i;
			sum%=2009;
			a[i]=sum;
		}
	while(scanf("%d",&n)!=EOF){
		if(n==0) printf("1\n");
		else if(n>40) printf("0\n");
		else printf("%d\n",a[n]);
	}
}
