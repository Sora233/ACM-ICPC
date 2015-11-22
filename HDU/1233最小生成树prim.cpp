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
int city,road;
int dis[1050];
int used[1050];
struct Edg{
	int to,cost;
}p;
vector<Edg>G[1050];
void prim(){
	int ans=0;
	memset(used,0,sizeof(used));
	for(int i=1;i<=city;++i) dis[i]=0xfffffff;
	for(int i=0;i<G[1].size();++i) dis[G[1][i].to]=G[1][i].cost;
	used[1]=1;
	dis[1]=0;
	for(int l=1;l<city;++l){
		int minx=0xfffffff,vert=0;
		for(int i=2;i<=city;++i)
			if(!used[i]&&dis[i]<minx) minx=dis[i],vert=i;
		used[vert]=1;
		ans+=minx;
		for(int i=0;i<G[vert].size();++i){
			if(!used[G[vert][i].to]&&G[vert][i].cost<dis[G[vert][i].to]) dis[G[vert][i].to]=G[vert][i].cost;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int a,b;
	while(scanf("%d",&city)!=EOF&&city){
		road=city*(city-1)/2;
		for(int i=0;i<=city;++i) G[i].clear();
		for(int i=0;i<road;++i){
			scanf("%d%d%d",&a,&b,&p.cost);
			p.to=a;
			G[b].push_back(p);
			p.to=b;
			G[a].push_back(p);
		}
		prim();
	}
}

