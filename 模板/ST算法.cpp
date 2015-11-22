void ST(int a[], int n){
    for(int i = 1; i <= n; ++i) dp[i][0] = a[i]; //下标从1开始
    for(int j = 1; (1<<j) <= n; ++j){
        for(int i = 1; i + (1<<j)-1 <= n; ++i){
            dp[i][j] = min(dp[i][j-1], dp[i+(1<<j-1)][j-1]);
        }
    }
}
int query(int a, int b){ //要保证a<b
    int k = (int) (log(b - a + 1)/log(2));
    return min(dp[a][k], dp[b-(1<<k)+1][k]);
}
