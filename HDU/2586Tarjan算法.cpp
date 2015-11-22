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
#define pii pair<int,int>
using namespace std;
const int MN=40005;
int seed[MN],dis[MN],vis[MN],ans[MN];
vector<pii >G[MN];
vector<pii >Qes[MN];
int find(int x){
	return seed[x]<0?x:seed[x]=find(seed[x]);
}
void join(int a,int b){ //°Ñb¼ÓÈëa 
	a=find(a),b=find(b);
	if(a==b) return;
	seed[a]+=seed[b];
	seed[b]=a;
}
void lca(int u){
	vis[u]=1;
	for(int i=0;i<G[u].size();++i){
		int v=G[u][i].first,w=G[u][i].second;
		if(vis[v]) continue;
		dis[v]=dis[u]+w;
		lca(v);
		join(u,v);
	}
	for(int i=0;i<Qes[u].size();++i){
		int v=Qes[u][i].second;
		if(vis[v])
		ans[Qes[u][i].first]=dis[v]+dis[u]-2*dis[find(v)];
	}
}
int main(){
	int T,a,b,c;
	scanf("%d",&T);
	while(T--){
		int city,Q;
		scanf("%d%d",&city,&Q);
		for(int i=0;i<=city;++i){
			G[i].clear();
			Qes[i].clear();
		}
		memset(seed,-1,sizeof(seed));
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		for(int i=1;i<city;++i){
			scanf("%d%d%d",&a,&b,&c);
			G[a].push_back(make_pair(b,c));
			G[b].push_back(make_pair(a,c));
		}
		for(int i=0;i<Q;++i){
			scanf("%d%d",&a,&b);
			Qes[a].pb(make_pair(i,b));
			Qes[b].pb(make_pair(i,a));
		}
		lca(1);
		for(int i=0;i<Q;++i) printf("%d\n",ans[i]);
	}
}

