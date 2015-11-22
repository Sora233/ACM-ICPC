#include<cstring>
#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
#define pb push_back
#define pii pair<int,int>
#define LL __int64
#define INF 0x7fffffff
#define LLINF 0x7fffffffffffffff
using namespace std;
const int N =55005;
struct eg{
    int u, v, w;
    eg(){}
    eg(int a, int b, int c) { u = a, v = b, w = c; }
}edg[N<<4];
int fir[N<<4], nex[N<<4], ecnt;
void add(int a, int b, int c){
    edg[ecnt] = eg(a, b, c);
    nex[ecnt] = fir[a], fir[a] = ecnt++;
}
int dis[N];
bool vis[N];
int spfa(int s, int n){
    for(int i = 0 ; i <= n; ++i) dis[i] = -INF, vis[i] = 0;
    queue<int>q;
    dis[s] = 0; vis[s] = 1;
    q.push(s);
    while( !q.empty() ){
        int u = q.front();
        for(int k = fir[u]; k != -1; k = nex[k]){
            int v = edg[k].v, w = edg[k].w;
            if(dis[v] < dis[u] + w){
                dis[v] = dis[u] + w;
                if( !vis[v] ){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        q.pop(); vis[u] = 0;
    }
    return dis[n];
}
int main(){
    int a, b, c, n, l, r;
    while( scanf("%d", &n) != EOF ){
        memset(fir, -1, sizeof(fir));
        l = 50005, r = 0, ecnt = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d %d %d", &a, &b, &c);
            a += 1, b += 1;
            add(a-1, b, c); // d[b] - d[a-1] >= c
            l = min (a, l);
            r = max (b, r);
        }
        for(int i = l; i <= r; ++i){
            add(i-1, i, 0);          //  d[i] - d[i-1] >= 0
            add(i, i-1, -1);          //  d[i-1] - d[i] >= -1
        }
        printf("%d\n", spfa(l-1, r) );
    }
}
