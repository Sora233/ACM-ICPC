#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int n,m; 
vector<int>G[250];
int color[250],used[250],match[250];
void ins(){
	memset(color,0,sizeof(color));
	memset(match,-1,sizeof(match));
	for(int i=0;i<250;++i) G[i].clear();
}
bool bipartite(int u){ //黑白法判定二分图 
	for(int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if(color[v]==color[u]&&color[v]) return 0;
		if(!color[v]){
			color[v]=3-color[u];
			if(!bipartite(v)) return 0;
		}
	}
	return 1;
}
bool find(int x){//匈牙利算法求最大匹配 
	for(int i=0;i<G[x].size();++i){
		int v=G[x].at(i);
		if(!used[v]){
			used[v]=1;
			if(match[v]==-1||find(match[v])){
				match[v]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int a,b,s;
	while(cin>>n>>m){
		ins();
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			G[a].push_back(b);
			G[b].push_back(a);
			s=a;
		}
		if(!bipartite(s)) {
			printf("No\n");
			continue;
		}
		int ans=0;
		for(int i=0;i<=n;++i){
			memset(used,0,sizeof(used));
			if(find(i)) ans+=1;
		}
		printf("%d\n",ans/2);
	}
}

