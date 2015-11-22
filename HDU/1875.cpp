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
const double esp=1e-9;
int seed[105];
int find(int x){
	return seed[x]<0?x:seed[x]=find(seed[x]);
}
int join(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return 0;
	if(seed[a]<seed[b]) seed[a]+=seed[b], seed[b]=a;
	else seed[b]+=seed[a],seed[a]=b;
	return 1;
}
struct node{
	int x,y;
	double cost;
}s1[100],edg[100005];
int dis2(node a,node b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int city,road;
int cmp(node a,node b){
	return a.cost<b.cost;
}
double krul(){
	double res=0;
	int flag=0;
	for(int i=0;i<road;++i){
		if(join(edg[i].x,edg[i].y)) res+=edg[i].cost,flag+=1;
	}
	if(flag!=city-1) return -1;
	return res;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(seed,-1,sizeof(seed));
		scanf("%d",&city);
		for(int i=0;i<city;++i){
			scanf("%d %d",&s1[i].x,&s1[i].y);
		}
		int c=0;
		for(int i=0;i<city;++i){
			for(int j=i;j<city;++j){
				if(i==j) continue;
				int l=dis2(s1[i],s1[j]);
				if(l<100||l>1000000) continue;
				edg[c].x=j,edg[c].y=i,edg[c++].cost=100*sqrt(l);
			}
		}
		road=c;
		sort(edg,edg+c,cmp);
		double ans=krul();
		if(fabs(ans+1)<esp) printf("oh!\n");
		else printf("%.1f\n",ans);
	}
}

