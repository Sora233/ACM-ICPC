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
#pragma comment(linker, "/STACK:102400000,102400000") //Õ‚π“’ª
using namespace std;
const int N =300005;
struct eg{
    int u, v, nex;
    eg(int a, int b, int c){ u = a, v = b, nex = c; }
    eg(){}
}edg[N*2];
int fir[N*2], ecnt;
void add(int a, int b){
    edg[ecnt] = eg(a, b, fir[a]);
    fir[a] = ecnt++;
    edg[ecnt] = eg(b, a, fir[b]);
    fir[b] = ecnt++;
}
int ver[N*2], R[N*2], first[N*2], vcnt;
bool vis[N];
void dfs(int u, int dep){
    vis[u] = 1, ver[++vcnt] = u, R[vcnt] = dep, first[u] = vcnt;
    for(int k = fir[u]; k != -1; k = edg[k].nex){
        int v = edg[k].v;
        if( !vis[v] ){
            dfs(v, dep+1);
            ver[++vcnt] = u, R[vcnt] = dep;
        }
    }
}
int dp[N*2][20][2];
void ST(int n){
    for(int i = 1; i <= n; ++i) dp[i][0][0] = dp[i][0][1] = i;
    for(int j = 1; (1<<j) <= n; ++j)
    for(int i = 1; i + (1<<j)-1 <= n; ++i){
        int a = dp[i][j-1][0], b = dp[i+(1<<j-1)][j-1][0];
        dp[i][j][0] = R[a] > R[b] ? b : a;
        a = dp[i][j-1][1], b = dp[i+(1<<j-1)][j-1][1];
        dp[i][j][1] = R[a] > R[b] ? a : b;
    }
}
void query1(int l, int r, int &mi, int &ma){
    int k = (int)(log2(r - l +1.0)+0.000005);
    if(l > r) swap(l, r);
    int a = dp[l][k][0], b = dp[r-(1<<k)+1][k][0];
    mi = R[a] > R[b]? b : a;
    a = dp[l][k][1], b = dp[r-(1<<k)+1][k][1];
    ma = R[a] > R[b]? a : b;
}
int query2(int l, int r){
    int k = (int)log2(r - l +1.0);
    int a = dp[l][k][0], b = dp[r-(1<<k)+1][k][0];
    return R[a] > R[b] ? b : a;
}
int LCA(int u, int v){
    if(u > v) swap(u, v);
    return ver[query2(u, v)];
}
int main(){
    int n, q, a, b;
    while( scanf("%d", &n) != EOF ){
        memset(fir, -1, sizeof(fir));
        memset(vis, 0, sizeof(vis));
        ecnt = vcnt = 0;
        for(int i = 1; i < n; ++i){
            scanf("%d %d", &a, &b);
            add(a, b);
        }
        dfs(1, 1);
        ST(n*2-1);
        scanf("%d", &q);
        while(q--){
            int mi, ma, l, r;
            scanf("%d %d", &l, &r);
            query1(first[l], first[r], mi, ma);
            printf("%d\n", LCA(mi, ma) );
        }
    }
}
