#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
#include<ctime>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
#define INF 0xfffffff
using namespace std;
int map[505][505];
int dis[505];
vector<int>G[505];
bool bfs(int s,int t,int n){
    int u,v;
    memset(dis,-1,sizeof(dis));
    dis[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        u=q.front();q.pop();
        for(int i=0;i<G[u].size();++i){
        	int v=G[u][i];
            if(map[u][v]>0&&dis[v]<0){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return dis[t]>0;
}
int dfs(int s,int t,int n,int low){
     if(s==t) return low;
     int a=0;
     for(int i=0;i<G[s].size();++i){
     	int v=G[s][i];
        if(map[s][v]>0&&dis[v]==dis[s]+1&&(a=dfs(v,t,n,min(low,map[s][v])))){
            map[s][v]-=a;
            map[v][s]+=a;
            return a;
        }
     }
     return 0;
}
void Dinic(int s,int t,int n){ //Dinic算法 用BFS构造层次网络 DFS连续增广
    int a,ans=0;
    while(bfs(s,t,n)){
        while(a=dfs(s,t,n,INF)) ans+=a;
    }
    printf("%d\n",ans);
}
int main(){
    int s,t,n,m,a,b,w;
    while(scanf("%d%d",&m,&n)!=EOF){
        memset(map,0,sizeof(map));
        for(int i=0;i<=n;++i) G[i].clear();
        s=1,t=n;
        for(int i=0;i<m;++i){
            scanf("%d%d%d",&a,&b,&w);
            map[a][b]+=w; // 最初的0流 所以反向边流量都是0 最初的网络就是残留网络 满足dinic的构造残留网络 
            G[a].pb(b);
            G[b].pb(a);
        }
        Dinic(s,t,n);
    }
}
