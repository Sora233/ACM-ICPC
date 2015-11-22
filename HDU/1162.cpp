#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<string>
using namespace std;
int seed[105];
int find(int x){
	return seed[x]<0?x:seed[x]=find(seed[x]);
}
int join(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return 0;
	if(seed[a]>seed[b]) seed[b]+=seed[a],seed[a]=b;
	else seed[a]+=seed[b],seed[b]=a;
	return 1;
}
struct node{
	double x,y;
}p[105];
struct Edg{
	int a,b;
	double dis;
}edg[10005];
double dis2(node a,node b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int cmp(Edg a,Edg b){
	return a.dis<b.dis;
}
int n,m;
double krul(){
	double res=0;
	for(int i=0;i<m;++i)
		if(join(edg[i].a,edg[i].b)) res+=sqrt(edg[i].dis);
	return res;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		m=0;
		memset(seed,-1,sizeof(seed));
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			edg[m].a=i,edg[m].b=j,edg[m++].dis=dis2(p[i],p[j]);
		sort(edg,edg+m,cmp);
		printf("%.2f\n",krul());
	}
}

