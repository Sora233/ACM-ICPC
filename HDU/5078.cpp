#include<cstdio>
#include<cmath>
main(){
	freopen("5078.in","r",stdin);
	int k,n;
	double difficulty=0,maxd=0;
	double x=0,y=0,dt,dx,dy,t=0;
	scanf("%d",&k);
	while(k--){
		scanf("%d",&n);
		while(n--){
			dt=t,dx=x,dy=y;
			scanf("%lf %lf %lf",&t,&x,&y);
			dt=t-dt,dx=fabs(x-dx),dy=fabs(y-dy);
			difficulty=sqrt(dx*dx+dy*dy)/dt;
			if(maxd<difficulty) maxd=difficulty;
		}
		printf("%.10f\n\n",maxd);
		difficulty=0;
		maxd=0;
		t=0,x=0,y=0;
	}
}
