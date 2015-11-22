#include<map>
#include<string>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define LL long long int
using namespace std;
int tox[8]={0,1,1,1,0,-1,-1,-1};
int toy[8]={1,1,0,-1,-1,-1,0,1};
struct peo{
	LL x,y;
}p[1005];
LL n,rad;
int cal(double x,double y){
	int res=0;
	for(int i=0;i<n;++i){
		if(2*p[i].x>= (2*x-rad) && 2*p[i].x<= (2*x+rad) && 2*p[i].y>= (2*y-rad) && 2*p[i].y<= (2*y+rad)) res+=1;
	}
	return res;
}
int SA(int s){
	double x = p[s].x, y = p[s].y, dx, dy;
	double tmper = 1;
	int res = cal(x, y);
	while(tmper > 1e-2){
		for(int i = 0; i < 8; ++i){
			dx = x + tox[i] * rad * tmper;
			dy = y + toy[i] * rad * tmper;
			int t = cal(dx,dy);
			if(t > res) x = dx, y = dy, res = t; 
		}
		tmper *= 0.2; 
	}
	return res;
}
int main(){
	while( scanf("%lld%lld",&n ,&rad) != EOF ){
		int ans=0;
		for(int i = 0; i < n; ++i) scanf("%lld%lld", &p[i].x, &p[i].y);
		for(int i = 0; i < n; ++i)
		{
			int t=SA(i);
			if(t>ans) ans=t;
		}
		printf("%d\n",ans);
	}
}

