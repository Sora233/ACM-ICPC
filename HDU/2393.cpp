#include<stdio.h>
#include<math.h>
const double esp=1e-9;
int main(){
	double a,b,c;
	int T;
	while(scanf("%d",&T)!=EOF){
	for(int ca=1;ca<=T;++ca)
	{
		printf("Scenario #%d:\n",ca);
		scanf("%lf %lf %lf",&a,&b,&c);
		if(fabs(a*a+b*b-c*c)<esp||fabs(a*a+c*c-b*b)<esp||fabs(b*b+c*c-a*a)<esp) printf("yes\n");
		else printf("no\n");
		printf("\n");
	}
}
return 0;
}
