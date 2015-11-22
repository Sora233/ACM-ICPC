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
using namespace std;
int map[505][505],n,m,s,e;//n 边 m 点
int path[505],flow[505];
int bfs(){
    queue<int>q;
    int i,t;
    memset(path,-1,sizeof(path));
    path[s]=0,flow[s]=0xfffffff;
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        if(u==e) break; //搜到终点 已找到增广路
        for(int i=1;i<=m;++i){
            if(path[i]==-1&&map[u][i]){
                flow[i]=min(flow[u],map[u][i]);
                q.push(i);
                path[i]=u;// path[i]储存i的前一个结点
            }
        }
    }
    if(path[e]==-1) return -1;
    return flow[e];
}
int EK(){
    int res=0,step,now,pre;
    while((step=bfs())!=-1){
        res+=step;
        now=e;
        while(now!=s){ //改进一条路
            pre=path[now];
            map[pre][now]-=step;
            map[now][pre]+=step;
            now=pre;
        }
    }
    return res;
}
int main(){
    int a,b,c;
    while(scanf("%d%d",&n,&m)){
        memset(map,0,sizeof(map));
        for(int i=0;i<n;++i) {
            scanf("%d%d%d",&a,&b,&c);
            map[a][b]+=c;
        }
        s=1,e=m;
        printf("%d\n",EK());
    }
}
