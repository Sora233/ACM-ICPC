#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<functional>
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
#define LL __int64
#define INF 0x1fffffff
#define LLINF 0x7fffffffffffffff
using namespace std;
const int N = 1005;
const int M = 100005;
struct eg{
    int u, v, dis;
    eg(){}
    eg(int a, int b, int c){
        u = a, v= b, dis = c;
    }
}edg[M<<4], redg[M<<4];
int n, m, s, t, ecnt, recnt;
int fir[M<<4], nex[M<<4], rfir[M<<4], rnex[M<<4];
void add(int a, int b, int c){
    edg[ecnt] = eg(a, b, c);
    nex[ecnt] = fir[a], fir[a] = ecnt++;
}
void radd(int a, int b, int c){
    redg[recnt] = eg(a, b, c);
    rnex[recnt] = rfir[a], rfir[a] = recnt++;
}

struct net{
    int u, v, cap;
    net(){}
    net(int a, int b, int c){ u = a, v = b, cap = c; }
}netedg[M<<2];
int ffir[M<<2], nnex[M<<2], flowcnt;
void addnet(int a, int b, int c = 1){
     netedg[flowcnt] = net(a, b, c);
     nnex[flowcnt] = ffir[a], ffir[a] = flowcnt++;
     netedg[flowcnt] = net(b, a, 0);
     nnex[flowcnt] = ffir[b], ffir[b] = flowcnt++;
}
struct node{
    int u, dis;
    node(){}
    node(int a, int b){ u = a, dis = b; }
    bool operator < (node a) const{
        return dis > a.dis;
    }
};
int dis1[N], dis2[N], vis[N], shore;
void exdijkstra(int s, int dis[], int fir[], int nex[], eg edg[]){
    for(int i = 0; i <= n; ++i) dis[i] = INF, vis[i] = 0;
    dis[s] = 0;
    priority_queue<node>q;
    q.push( node(s, 0) );
    node now;
    while( !q.empty() ){
        now = q.top(); q.pop();
        if( vis[now.u] || dis[now.u] != now.dis ) continue;
        int u = now.u;
        vis[u] = 1;
        for(int k = fir[u]; k != -1; k = nex[k]){
            int v = edg[k].v, w = edg[k].dis;
            if( dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                q.push( node(v, dis[v]) );
            }
        }
    }
}
int lev[N], q[N<<3], top, tail;
bool Bfs(int s, int t){
    memset(lev, -1, sizeof(lev));
    top = tail = 0;
    lev[s] = 0; q[tail++] = s;
    while( top < tail ){
        int u = q[top++];
        if( u == t) return 1;
        for(int k = ffir[u]; k != -1; k = nnex[k]){
            int v = netedg[k].v;
            if( netedg[k].cap && lev[v] == -1){
                lev[v] = lev[u] + 1;
                q[tail++] = v;
            }
        }
    }
    return 0;
}
int Dfs(int s, int t, int low){
    if( s == t ) return low;
    int a = 0, res = 0;
    for(int k = ffir[s]; k != -1; k = nnex[k]){
        int v = netedg[k].v;
        if(netedg[k].cap && lev[v] == lev[s] + 1 ){
            a = Dfs(v, t , min(low - res, netedg[k].cap));
            netedg[k].cap -= a;
            netedg[k^1].cap += a;
            res += a;
            if(res == low) return res;
        }
    }
    if(res == 0) lev[s] = -1;
    return res;
}
int Dinic(int s, int t){
    int res = 0, minflow;
    while( Bfs(s, t) ){
        res += Dfs(s, t,INF);
    }
    return res;
}
int main(){
    int T, a, b, c;
    scanf("%d", &T);
    while( T-- ){
        ecnt = 0, flowcnt = 0, recnt = 0;
        memset(fir, -1, sizeof(fir));
        memset(ffir, -1, sizeof(ffir));
        memset(rfir, -1, sizeof(rfir));
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m ; ++i){
            scanf("%d %d %d", &a, &b, &c);
            add(a, b, c);
            radd(b, a, c);
        }
        scanf("%d %d", &s, &t);
        int ans = 0;
        exdijkstra(s, dis1, fir, nex, edg);
        exdijkstra(t, dis2, rfir, rnex, redg);
        for(int i = 0; i < ecnt; ++i){
            if(dis1[edg[i].u] + edg[i].dis + dis2[edg[i].v] == dis1[t]) addnet(edg[i].u, edg[i].v);
        }
        printf("%d\n", Dinic(s, t) );
    }
}
