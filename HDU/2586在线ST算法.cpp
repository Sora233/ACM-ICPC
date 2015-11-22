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
const int N =40005;
int n, m;
struct eg{
    int u, v, dis;
    eg(){}
    eg(int a, int b, int c){ u = a, v = b, dis = c; }
}edg[N*2];
int fir[N*2], nex[N*2], ecnt;
void add(int a, int b, int c){
    edg[ecnt] = eg(a, b, c);
    nex[ecnt] = fir[a], fir[a] = ecnt++;
    edg[ecnt] = eg(b, a, c);
    nex[ecnt] = fir[b], fir[b] = ecnt++;
}
int ver[N*2], R[N*2], first[N*2], dist[N];
int vcnt;
bool vis[N];
void dfs(int u, int dep){
    vis[u] = 1, ver[++vcnt] = u, first[u] = vcnt, R[vcnt] = dep;
    for(int k = fir[u]; k != -1; k = nex[k]){
        int v = edg[k].v;
        if(!vis[v]){
            dist[v] = dist[u] + edg[k].dis;
            dfs(v, dep+1);
            ver[++vcnt] = u, R[vcnt] = dep;
        }
    }
}
int dp[2*N][20];
void ST(int n){ //第一个数从1开始 n为数的个数
    for(int i = 1; i <= n; ++i) dp[i][0] = i;
    for(int j = 1; (1<<j) <= n; ++j){
        for(int i = 1; i + (1<<j)-1 <= n; ++i){
            int a = dp[i][j-1], b = dp[i+(1<<j-1)][j-1];
            dp[i][j] = R[a] > R[b] ? b : a;
        }
    }
}
int query(int a, int b){ // 注意参数a<b
    int k = (int) log2(b-a+1);
    int s1 = dp[a][k], s2 = dp[b-(1<<k)+1][k]; //保证 a~a+2^k-1 和 b-2^k+1~b 覆盖a~b 注意这个位置+1会覆盖
    return R[s1] > R[s2] ? s2 : s1;
}
int LCA(int u, int v){
    int x = first[u], y = first[v];
    if(x > y) swap(x, y);
    return ver[query(x, y)];
}
int main(){
    int T, a, b, c;
    scanf("%d", &T);
    while( T-- ){
        scanf("%d%d", &n, &m);
        memset(fir, -1, sizeof(fir));
        memset(vis, 0, sizeof(vis));
        vcnt = ecnt = dist[1] = 0;
        for(int i = 1; i < n; ++i){
            scanf("%d %d %d", &a, &b, &c);
            add(a, b, c);
        }
        dfs(1, 1);
        ST(2*n-1);
        while( m-- ){
            int u, v;
            scanf("%d %d", &u, &v);
            printf("%d\n", dist[u] + dist[v] - 2*dist[LCA(u,v)]);
        }
    }
}
