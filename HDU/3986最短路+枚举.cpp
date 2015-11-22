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
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 1005, M = 50005;
struct eg{
    int v, w, nex;
    eg(){}
    eg(int b, int c, int d){ v = b, w = c, nex = d; }
}edg[M*2];
int fir[M*2], ecnt;
void add(int a, int b, int c){
    edg[ecnt] = eg(b, c, fir[a]);
    fir[a] = ecnt ++;
    edg[ecnt] = eg(a, c, fir[b]);
    fir[b] = ecnt ++;
}
struct node{
    int u, d;
    node(int a, int b){ u = a, d = b; }
    bool operator < (node a) const{
        return d > a.d;
    }
};
int prek[N], preu[N], dis[N];
bool vis[N];
queue<int>q;
int spfa(int s, int n){
    for(int i = 0; i <= n; ++i) dis[i] = INF, vis[i] = 0;
    while( !q.empty() ) q.pop();
    dis[s] = 0, vis[s] = 1; q.push(s);
    while( !q.empty() ){
        int u = q.front(); q.pop(); vis[u] = 0;
        for(int k = fir[u]; k != -1; k = edg[k].nex){
            int v = edg[k].v, w = edg[k].w;
            if(w == INF) continue;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                prek[v] = k;
                preu[v] = u;
                if( !vis[v] ) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis[n];
}
vector<int>path;
void addpath(int s, int n){
    while(n != s){
        path.pb(prek[n]);
        n = preu[n];
    }
}

int main(){
    int n, m, a, b, c, T;
    scanf("%d", &T);
    while( T-- ){
        scanf("%d %d", &n, &m);
        memset(fir, -1, sizeof(fir));
        ecnt = 0;
        for(int i = 0 ; i < m; ++i){
            scanf("%d %d %d", &a, &b, &c);
            add(a, b, c);
        }
        int ans = 0;
        path.clear();
        spfa(1, n);
        addpath(1, n);
        for(int i = 0; i < path.size(); ++i){
            int tmp = edg[path[i]].w;
            edg[path[i]].w = INF;
            edg[path[i]^1].w = INF;
            ans = max(ans, spfa(1, n) );
            edg[path[i]].w = tmp;
            edg[path[i]^1].w = tmp;
        }
        if(ans == INF) puts("-1");
        else printf("%d\n", ans);
    }
}
