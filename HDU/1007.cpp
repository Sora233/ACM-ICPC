#include<stdio.h>
#include<cmath>
#include<string.h>
#include<algorithm>
const double ESP=1e-9;
struct node{
	double x,y;
};
bool cmp(node a,node b){
	return b.y>a.y;
}
double DIS(node a,node b){
	double dis=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	return dis;
}
node point[100001];
int main(){
	int N;
	while(scanf("%d",&N)!=EOF){
		if(!N) break;
		memset(point,0,sizeof(point));
		for(int i=0;i<N;i++){
			scanf("%lf%lf",&point[i].x,&point[i].y);
		}
		std::sort(point,point+N,cmp);
		double dis=1e100;
		for(int i=1;i<N;i++){
			double d=DIS(point[i],point[i-1]);
			if(d<dis) dis=d;
		}
		printf("%.2f\n",sqrt(dis)/2);
    }
}
