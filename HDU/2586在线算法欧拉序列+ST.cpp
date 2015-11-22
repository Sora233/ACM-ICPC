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
int k[MN];
int scq[MN],cort;//记录欧拉序列 
int dp[MN][20],depth[MN],pos[MN],dis[MN],vis[MN];
vector<pii >G[MN];
int city,road;
void dfs(int u,int dept){
	scq[++cort]=u;//按照搜到的顺序记录欧拉序列
	depth[cort]=dept;
	if(pos[u]==-1) pos[u]=cort;
	vis[u]=1;
	for(int i=0;i<G[u].size();++i){
		int v=G[u][i].first;
		int w=G[u][i].second;
		if(vis[v]) continue;
		dis[v]=dis[u]+w;
		dfs(v,dept+1);
		scq[++cort]=u;
		depth[cort]=dept;
	}
}
int mmin(int a,int b){
	return depth[a]<=depth[b]?a:b;
}
void preST(){
	memset(pos,-1,sizeof(pos));
	memset(depth,0,sizeof(depth));
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	cort=0;
	dfs(1,1);
	for(int j=1;j<=k[city];++j)
	for(int i=1;i+(1<<j)<=city;++i)
		dp[i][j]=mmin(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
	l=pos[l],r=pos[r];
	if(l>r) swap(l,r);
	int md=k[r-l+1];
	int x=dp[l][md],y=dp[r-(1<<md)+1][md];
	return scq[mmin(x,y)];
}
int main(){
	k[0]=-1;
	for(int i=1;i<MN;++i) k[i]=(i&&(i-1)==0)?k[i-1]+1:k[i-1];
	int T,a,b,c,Q;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&city,&Q);
		for(int i=0;i<road;++i){
			scanf("%d%d%d",&a,&b,&c);
			G[a].pb(make_pair(b,c));
			G[b].pb(make_pair(a,c));
		}
		preST();
		while(Q--){
			int x,y;  
            scanf("%d%d",&x,&y);  
            int fa=query(x,y);  
            printf("%d\n",dis[x]+dis[y]-2*dis[fa]); 

		}
	}
}

