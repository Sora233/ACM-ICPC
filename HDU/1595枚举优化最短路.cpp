#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<functional>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<ctime>
#define pb push_back
#define pii pair<int,int>
#define LL __int64
#define INF 0x7fffffff
#define LLINF 0x7fffffffffffffff
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 1005, M = 500000;

int maz[N][N];
void add(int a, int b, int c){
    if(maz[a][b] == -1 || maz[a][b] > c){
        maz[a][b] = maz[b][a] = c;
    }
}

struct node{
    int u, d;
    node(int a, int b){ u = a, d = b; }
    bool operator < (node a) const{
        return d > a.d;
    }
};
int pre[N], dis[N], vis[N];
int exdijkstra(int s, int n){
    for(int i = 0; i <= n; ++i) dis[i] = INF, vis[i] = 0;
    dis[s] = 0;
    priority_queue<node>q;
    q.push( node(s, 0) );
    while( !q.empty() ){
        int u = q.top().u, d = q.top().d; q.pop();
        if( vis[u] || dis[u] != d ) continue;
        vis[u] = 1;
        for(int v = 1 ; v <= n; ++v){
            int w = maz[u][v];
            if(w == -1) continue;
            if(!vis[v] && dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pre[v] = u;
                q.push( node(v, dis[v]) );
            }
        }
    }
    return dis[n];
}

vector<pii >path;
void addpath(int s, int n){
    while(n != s){
        path.pb(make_pair(pre[n], n));
        n = pre[n];
    }
}

int main(){
    int n, m, a, b, c;
    while( scanf("%d %d", &n, &m) != EOF ){
        memset(maz, -1, sizeof(maz));
        for(int i = 0 ; i < m; ++i){
            scanf("%d %d %d", &a, &b, &c);
            add(a, b, c);
        }
        path.clear();
        exdijkstra(1, n);
        addpath(1, n);
        int ans = 0;
        for(int i = 0; i < path.size(); ++i){
            int u = path[i].first, v = path[i].second;
            int tmp = maz[u][v];
            maz[u][v] = maz[v][u] = -1;
            ans = max(ans, exdijkstra(1, n) );
            maz[u][v] = maz[v][u] = tmp;
        }
        printf("%d\n", ans);
    }
}
