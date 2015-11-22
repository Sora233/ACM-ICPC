#include<bits/stdc++.h>
using namespace std;
int dp[25][1005];
int num[25][1005];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= m; ++j)
                dp[i][j] = -0x7ffffff;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &num[i][j]);
        dp[1][1] = num[1][1];
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(i-1 >= 1) dp[i][j] = max(dp[i][j], dp[i-1][j] + num[i][j]);
                if(j-1 >= 1) dp[i][j] = max(dp[i][j], dp[i][j-1] + num[i][j]);
                for(int k = 2; k <= j; ++k){
                    if(j%k == 0){
                        dp[i][j] = max(dp[i][j], dp[i][j/k] + num[i][j]);
                    }
                }
            }
        }
        printf("%d\n", dp[n][m]);
    }
}
