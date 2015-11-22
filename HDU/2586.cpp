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
struct node{
	int to,val;
}p;
struct ds{
	int now,e,dis;
};
int n,m,ans;
vector<node>G[40005];
bool vis[40005];
void dfs(int now,int e,int dis){
	stack<ds>s;
	ds k,nn;
	k.now=now,k.e=e,k.dis=dis;
	s.push(k);
	while(!s.empty()){
		nn=s.top();
		vis[nn.now]=1;
		s.pop();
		int l=G[nn.now].size();
		for(int i=0;i<l;++i){
			k=nn;
			int tt=G[nn.now][i].to;
			if(vis[tt])continue;
			if(tt==e) ans=min(k.dis+G[k.now][i].val,ans);
			k.dis+=G[k.now][i].val,k.now=tt;
			s.push(k);
		}
	}
}
int main(){
	int t,a,b,c;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		
		for(int i=0;i<=n;++i) G[i].clear();
		for(int i=0;i<n-1;++i){
			scanf("%d%d%d",&a,&b,&p.val);
			p.to=b;
			G[a].push_back(p);
			p.to=a;
			G[b].push_back(p);
		}
		while(m--){
			memset(vis,0,sizeof(vis));
			scanf("%d%d",&a,&b);
			if(a==b){
				printf("0\n");
				continue;
			}
			ans=0xfffffff;
			dfs(a,b,0);
			printf("%d\n",ans);
		}
	}
}

