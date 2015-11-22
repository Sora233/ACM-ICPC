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
int n, f, d, m;
const int M = 100000;
const int N = 100000;

struct eg{
    int u, v, cap;
    eg(){}
    eg(int a, int b, int c){ u = a, v = b, cap = c; }
}edg[M*60];
int fir[M*60], nex[M*60], ecnt, s, t;
void add(int a, int b, int c){
    edg[ecnt] = eg(a, b, c);
    nex[ecnt] = fir[a], fir[a] = ecnt++;
    edg[ecnt] = eg(b, a, 0);
    nex[ecnt] = fir[b], fir[b] = ecnt++;
}
int lev[N], q[N*60], top, tail;
bool Bfs(int s, int t){
    memset(lev, -1, sizeof(lev));
    top = tail = 0;
    lev[s] = 0; q[tail++] = s;
    while( top < tail ){
        int u = q[top++];
        if( u == t ) return 1;
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
int Dfs(int s, int t, int low){
    if( s == t ) return low;
    int a = 0, res = 0;
    for(int k = fir[s]; k != -1; k = nex[k]){
        int v = edg[k].v;
        if(edg[k].cap && lev[v] == lev[s] +1 ){
            a = Dfs(v, t, min(low - res, edg[k].cap) );
            edg[k].cap -= a;
            edg[k^1].cap += a;
            res += a;
            if(res == low) return res;
        }
    }
    if(res == 0 ) lev[s] = -1;
    return res;
}
int Dinic(int s, int t){
    int res = 0, minflow;
    while( Bfs(s, t) ){
        while( minflow = Dfs(s, t, INF) ) res += minflow;
    }
    return res;
}

//  s = 0
// 食物              饮料                  人
// 1~f              f+1~f+d              f+d+1~f+d+n
// t = f+d+2n+1
// 源点->食物->->人1->人2->饮料->汇点
//s -a> (1~f) -1> (f+d+1~f+d+n) -1> (f+d+n+1~f+d+n+n) -1> (f+1~f+d) -a> t;
int main(){
    int tmp, a, b, c;
    char p[500];
    s = 0;
    while( scanf("%d %d %d%", &n, &f, &d) != EOF ){
        memset(fir, -1, sizeof(fir));
        t = f+d+n+n+1; ecnt = 0;
        for(int i = 1; i <= f; ++i){
            scanf("%d", &a);
            add(s, i, a);
        }
        for(int i = 1; i <= d; ++i){
            scanf("%d", &a);
            add(f+i, t, a);
        }
        for(int i = 1; i <= n; ++i)
            add(f+d+i, f+d+n+i, 1);
        for(int i = 1 ;i <= n; ++i){
            scanf("%s", p);
            for(int j = 1; j <= f; ++j){
                if(p[j-1] == 'Y'){
                    add(j, f+d+i, 1);
                    //printf("ad(%d, %d)\n", j, f+d+i);
                }
            }
        }
        for(int i = 1; i <= n; ++i){
            scanf("%s", p);
            for(int j = 1; j <= d; ++j){
                if(p[j-1] == 'Y'){
                    add(f+d+n+i, f+j, 1);
                    //printf("add(%d, %d)\n", f+d+n+i, f+j);
                }
            }
        }
        printf("%d\n", Dinic(s,t) );
    }
}
