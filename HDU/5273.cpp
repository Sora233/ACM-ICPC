#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 1005;
int a[N];
int ans[N][N];
int cnt[N];
int main(){
    int n, q;
    while( scanf("%d %d", &n, &q) != EOF ){
        memset(ans, 0, sizeof(ans));
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; ++i){
            ans[1][i] = ans[1][i-1];
            for(int j = 1; j < i; ++j){
                if( a[j] > a[i] ) ans[1][i] += 1;
            }
        }
        for(int i = 2; i <= n; ++i){
            memset(cnt, 0, sizeof(cnt));
            for(int j = i; j <= n; ++j){
                if( a[i-1] > a[j] ) cnt[j] = -1;
            }
            for(int j = n-1; j >= i; --j){
                cnt[j] += cnt[j+1];
                ans[i][j+1] = ans[i-1][j+1] + cnt[j];
                printf("ans[i-1][j]=%d, cnt[j]=%d\n", ans[i-1][j], cnt[j]);
                printf("ans[%d][%d]=%d\n", i, j, ans[i][j]);
            }
        }
        while( q-- ){
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", ans[l][r]);
        }
    }
    return 0;
}
