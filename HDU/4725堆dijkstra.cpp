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
#define INF 0x7fffffff
#define LLINF 0x7fffffffffffffff
using namespace std;
const int N = 1000005;
int n, m, levc, s, t;
struct st{
    int u, dis;
    st(){}
    st(int a, LL b){ u = a, dis = b; }
    bool operator < (st a)const{
        return dis > a.dis;
    }
};
struct eg{
    int u, v, w;
    eg(){}
    eg(int a, int b, int c) { u = a , v = b, w = c; }
}edg[N<<2];
int fir[N<<2], nex[N<<2], ecnt;
void add(int a, int b, int c){
    edg[ecnt] = eg(a, b, c);
    nex[ecnt] = fir[a], fir[a] = ecnt++;
}
priority_queue<st>q;
int dis[N];
bool vis[N];
void exdijkstra(int s, int n){
    for(int i = 1; i <= n; ++i) dis[i] = INF, vis[i] = 0;
    while( !q.empty() ) q.pop();
    dis[s] = 0;
    q.push( st(s, 0) );
    st now;
    int v, co;
    while( !q.empty() ){
        now = q.top(); q.pop();
        if( vis[now.u] ) continue;
        vis[now.u] = 1;
        for(int k = fir[now.u]; k != -1; k = nex[k]){
            v = edg[k].v;
            if( !vis[v] && dis[v] > now.dis + edg[k].w ){
                dis[v] = now.dis + edg[k].w;
                q.push( st(v, dis[v]) );
            }
        }
    }
}
int main(){
    int T, ca = 1, a, b, c;
    scanf("%d", &T);
    while( T-- ){
        scanf("%d %d %d", &n, &m, &levc);
        memset(fir, -1, sizeof(fir));
        ecnt = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a);
            add(i, n + 2*a-1, 0);
            add(n+2*a, i, 0);
        }
        for(int i = 1; i <= n; ++i){
            add( n + 2*i-1, n +2*(i+1), levc);
            add( n+2*(i+1)-1, n +2*i, levc);
        }
        for(int i = 0; i < m; ++i){
            scanf("%d %d %d", &a, &b, &c);
            add(a, b, c);
            add(b, a, c);
        }
        exdijkstra(1, n*3);
        if(dis[n] == INF) dis[n] = -1;
        printf("Case #%d: %d\n", ca++, dis[n] );
    }
}
