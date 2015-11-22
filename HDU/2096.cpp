#include<cstdio>
main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>=100) a%=100;
		if(b>=100) b%=100;
		printf("%d\n",(a+b)%100);
	}
}
