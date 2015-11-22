#include<cstdio>
#include<cmath>
main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		 int sum=0;
		 int i=0;
		 while(n){
		 	sum+=n%2*pow(10,i++);
		 	n/=2;
		 }
		 printf("%d\n",sum);
	}
}
