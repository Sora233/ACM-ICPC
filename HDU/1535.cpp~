#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define LL long long int
#define LLINF 0x177777777777777
using namespace std;
const int M = 1e6+5;
const int N = 1e6+5;

struct eg{
    int u, v, w, nex;
    eg(){}
    eg(int a, int b, int c, int d){ u = a, v = b, w = c, nex = d; }
}edg[M], redg[M];

int fir[N], rfir[N], ecnt, recnt;
LL ds[N], rds[N];

void add(int a, int b, int c){
    edg[ecnt] = eg(a, b, c, fir[a]);
    fir[a] = ecnt++;
}
void radd(int a, int b, int c){
    redg[recnt] = eg(a, b, c, rfir[a]);
    rfir[a] = recnt++;
}

int n, m;

void init(){
    ecnt = recnt = 0;
    memset(fir, -1, sizeof(fir));
    memset(rfir,-1, sizeof(rfir));
}

bool vis[N];
struct po{
    int u;
    LL dis;
    po(int a, LL b) { u = a, dis = b; }
    bool operator < (po a) const{
        return dis > a.dis;
    }
};
void exdijkstra(int s, LL dis[], eg edg[], int fir[]){
    priority_queue<po>q;
    for( int i = 0; i <= n; ++i ) dis[i] = LLINF, vis[i] = 0;
    dis[s] = 0;
    q.push( po(s, 0) );
    while( !q.empty() ){
        int u = q.top().u;
        LL ds = q.top().dis;
        q.pop();
        if( vis[u] || ds != dis[u] ) continue;
        vis[u] = 1;
        for(int k = fir[u]; k != -1; k = edg[k].nex){
            int v = edg[k].v, w = edg[k].w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                q.push( po(v, dis[v]) );
            }
        }
    }
}

int main(){
    int T, a, b, c;
    scanf("%d", &T);
    while( T-- ){
        init();
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; ++i){
            scanf("%d %d %d", &a, &b, &c);
            add(a, b, c);
            radd(b, a, c);
        }
        exdijkstra(1, ds, edg, fir);
        exdijkstra(1, rds, redg, rfir);
        LL ans = 0;
        for(int i = 1; i <= n; ++i){
            ans += ds[i] + rds[i];
        }
        printf("%lld\n", ans);
    }
}
