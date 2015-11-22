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
#define pb push_back
#pragma comment(linker, "/STACK:102400000,102400000")//手动开大栈区
using namespace std;
const int MN=10005;
struct pii{
	int first,second;
}p;
vector<pii>edg[MN];
vector<pii>Qs[MN];
short seed[MN];
int dis[MN];
int ans[1000005];
short liant[MN];
short ance[MN];
bool vis[MN];
int city,road,Query;
int find(int x,short ax[]){
	return ax[x]<0?x:ax[x]=find(ax[x],ax);
}
void join(int a,int b,short ax[]){
	a=find(a,ax),b=find(b,ax);
	if(a==b) return;
	ax[a]+=ax[b];
	ax[b]=a;
}
void ints(){
	memset(ans,0,sizeof(ans));
	for(int i=0;i<=city;++i){
		edg[i].clear();
		Qs[i].clear();
		seed[i]=liant[i]=-1;
		dis[i]=vis[i]=0;
	}
}
void lca(int u){
	vis[u]=1;
	ance[u]=u;
	for(int i=0;i<edg[u].size();++i){
		int v=edg[u][i].first,w=edg[u][i].second;
		if(vis[v]) continue;
		dis[v]=dis[u]+w;
		//printf("dis[%d]=%d=dis[%d]+%d\n",v,dis[v],u,w);
		lca(v);
		join(u,v,seed);
		ance[find(v,seed)]=u;
	}
	for(int i=0;i<Qs[u].size();++i){
		int v=Qs[u][i].second;
		int x=ance[find(v,seed)];
		if(vis[v]&&!ans[Qs[u][i].first]) {
		ans[Qs[u][i].first]=dis[v]+dis[u]-2*dis[v];
	//	printf("dis[v]=%d,dis[u]=%d,dis[find(v)]=%d,ans=%d+%d-2*%d\n",dis[v],dis[u],dis[find(v)],dis[v],dis[u],dis[find(v)]);
        }
	}
}
int main(){
	int a,b,c;
	while(scanf("%d%d",&city,&road)!=EOF){
		ints();
		scanf("%d",&Query);
		for(int i=0;i<road;++i){
			scanf("%d%d%d",&a,&b,&p.second);
			join(a,b,liant);
			p.first=b;
			edg[a].pb(p);
			p.first=a;
			edg[b].pb(p);
		}
		for(int i=0;i<Query;++i){
			scanf("%d%d",&p.first,&b);
			p.second=a;
			Qs[b].pb(p);
			p.first=b;
			Qs[a].pb(p);
			if(find(a,liant)!=find(b,liant)) ans[i]=-1;
		}
		for(int i=1;i<=city;++i){
			if(liant[i]<0) lca(i);
		}
		for(int i=0;i<Query;++i){
			if(ans[i]==-1) printf("Not connected\n");
			else printf("%d\n",ans[i]);
		}
	}
}

