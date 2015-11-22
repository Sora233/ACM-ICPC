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
struct Edg{
	int to,cost;
}p;
vector<Edg>G[105];
int used[105];
int dis[105];
void prim(int x){
	if(road<city-1){
		puts("?");
		return;
	}
	int ans=0,flag=1;
	memset(used,0,sizeof(used));
	used[x]=1;
	for(int i=1;i<=city;++i) dis[i]=0xfffffff;
	for(int i=0;i<G[x].size();++i) dis[G[x][i].to]=min(G[x][i].cost,dis[G[x][i].to]);
	dis[x]=0;
	for(int i=1;i<city;++i){
		int minx=0xfffffff,vert=0;
		for(int j=1;j<=city;++j)
			if(!used[j]&&minx>dis[j]) vert=j,minx=dis[j];
		if(minx==0xfffffff) {
			puts("?");
			return;
		}
		used[vert]=1;
		ans+=minx;
		for(int j=0;j<G[vert].size();++j){
			if(!used[G[vert][j].to]&&G[vert][j].cost<dis[G[vert][j].to]) dis[G[vert][j].to]=G[vert][j].cost;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int a,b,c;
	while(scanf("%d",&road)!=EOF&&road){
		scanf("%d",&city);
		for(int i=0;i<=city;++i) G[i].clear();
		for(int i=0;i<road;++i){
			scanf("%d%d%d",&a,&b,&p.cost);
			p.to=b;
			G[a].push_back(p);
			p.to=a;
			G[b].push_back(p);
			c=a;
		}
		prim(c);
	}
}

