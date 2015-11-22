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
struct eg{
    int u, v, cap;
    eg(){}
    eg(int a, int b, int c) { u = a, v = b, cap = c; }
}edg[2005];
int nex[2005], fir[2005], ecnt;
void add(int a, int b, int c){
    edg[ecnt] = eg(a, b, c);
    nex[ecnt] = fir[a], fir[a] = ecnt++;
    edg[ecnt] = eg(b, a, 0);
    nex[ecnt] = fir[b], fir[b] = ecnt++;
}
int n, m;
int lev[20];
bool Bfs(int s, int t){
    memset(lev, -1, sizeof(lev));
    queue<int>q;
    lev[s] = 0; q.push(s);
    while( !q.empty() ){
        int u = q.front(); q.pop();
        if( u == t ) return 1;
        for(int k = fir[u]; k != -1; k = nex[k]){
            int v = edg[k].v;
            if( edg[k].cap && lev[v] == -1){
                lev[v] = lev[u] + 1;
                q.push(v);
            }
        }
    }
    return 0;
}
int Dfs(int s, int t, int low){
    if( s == t ) return low;
    int a = 0;
    for(int k = fir[s]; k != -1; k = nex[k]){
        int v = edg[k].v;
        if(edg[k].cap && lev[v] == lev[s] +1 && (a = Dfs(v, t, min(low, edg[k].cap) ))){
            edg[k].cap -= a;
            edg[k^1].cap += a;
            return a;
        }
    }
    lev[s] = -1;
    return 0;
}
int Dinic(int s, int t){
    int res = 0, a;
    while( Bfs(s, t) ){
        while(a = Dfs(s, t, INF)) res += a;
    }
    return res;
}
int main(){
    int T, a, b, c, ca = 1;
    scanf("%d", &T);
    while(T--){
        memset(fir, -1, sizeof(fir));
        ecnt = 0;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; ++i){
            scanf("%d %d %d", &a, &b, &c);
            add(a, b, c);
        }
        printf("Case %d: %d\n", ca++, Dinic(1, n) );
    }
}
