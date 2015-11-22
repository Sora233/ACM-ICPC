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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int N = 200005;
struct eg{
    int u, v, cap;
    eg(){}
    eg(int a, int b, int c){ u = a, v = b, cap = c; }
}edg[N<<3];
int fir[N<<3], nex[N<<3], ecnt, s, t, n, m;
void add(int a, int b, int c){
    edg[ecnt] = eg(a, b, c);
    nex[ecnt] = fir[a] ,fir[a] = ecnt++;
    edg[ecnt] = eg(b, a, c);
    nex[ecnt] = fir[b], fir[b] = ecnt++;
}
int lev[N], q[N<<3], top, tail;
bool Bfs(int s, int t, int n){
    memset(lev, -1, sizeof(lev));
    top = tail = 0;
    lev[s] = 0; q[tail++] = s;
    while( top < tail ){
        int u = q[top++];
        if( u == t) return 1;
        for(int k = fir[u]; k != -1; k = nex[k]){
            int v = edg[k].v;
            if( edg[k].cap && lev[v] == -1){
                lev[v] = lev[u] + 1;
                q[tail++] = v;
            }
        }
    }
    return 0;
}
int Dfs(int s, int t, int n, int low){
    if( s == t ) return low;
    int a = 0;
    for(int k = fir[s]; k != -1; k = nex[k]){
        int v = edg[k].v;
        if(edg[k].cap && lev[v] == lev[s] +1 && (a = Dfs(v, t, n, min(low, edg[k].cap) ))){
            edg[k].cap -= a;
            edg[k^1].cap += a;
            return a;
        }
    }
    lev[s] = -1;
    return 0;
}
int Dinic(int s, int t, int n){
    int res = 0, minflow;
    while( Bfs(s, t ,n) ){
        while( (minflow = Dfs(s, t, n, INF)) ) res += minflow;
    }
    return res;
}
int main(){
    int T, a, b, c;
    scanf("%d", &T);
    while( T-- ){
        memset(fir, -1, sizeof(fir));
        ecnt = 0;
        int sx = INF, tx = -INF;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i){
            scanf("%d %d", &a, &b);
            if(a < sx) s = i, sx = a;
            if(a > tx) t = i, tx = a;
        }
        for(int i = 0; i < m; ++i){
            scanf("%d %d %d", &a, &b, &c);
            add(a, b, c);
        }
        printf("%d\n", Dinic(s, t, n+5) );
    }
}
