#include<cstdio>
#include<cmath>
using namespace std;
const double pi=3.1415926;
typedef struct{
	double x,y;
}Point;
main(){
	int t;
	double a,b,c,r,d;
	scanf("%d",&t);
	double x1,y1,x2,y2;
	while(t--){
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		a=sqrt(x1*x1+y1*y1);
		b=sqrt(x2*x2+y2*y2);
		c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		r=acos((b*b+a*a-c*c)/(2*a*b));
		d=r*(180/pi);
		printf("%.2f\n",d);
	}
}
