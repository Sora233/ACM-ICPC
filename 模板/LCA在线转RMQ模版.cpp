int ver[N*2], R[N*2], first[N], vcnt;
bool vis[N]; // 初始化vis vcnt 
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
int dp[N*2][20]; //第二维要大于logN 一般20够用了 
void ST(int n){ //序号都是从1开始的 
    for(int i = 1; i <= n; ++i) dp[i][0] = i;
    for(int j = 1; (1<<j) <= n; ++j)
    for(int i = 1; i + (1<<j)-1 <= n; ++i){
        int a = dp[i][j-1], b = dp[i+(1<<j-1)][j-1];
        dp[i][j] = R[a] > R[b]? b : a;
    }
}
int query(int x, int y){
    int k = (int)(log(y-x+1.0)/log(2.0));
    int s1 = dp[x][k], s2 = dp[y-(1<<k)+1][k];
    return R[s1] > R[s2] ? s2 : s1;
}
int LCA(int u, int v){ //返回u v的LCA 在线。 
    if( first[u] > first[v] ) swap(u, v);
    return ver[query(first[u], first[v])];
}
