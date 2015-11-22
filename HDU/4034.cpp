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
const int N = 1005;
int mat[N][N], n;
int dis[N][N];
bool vis[N][N];
int main(){
    int T, ca = 1;
    scanf("%d", &T);
    while( T-- ){
        int flag = 0, ans = 0;
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        for(int i = 1 ; i <= n; ++i)
            for(int j = 1; j <= n; ++j){
                scanf("%d", &mat[i][j]);
                dis[i][j] = mat[i][j];
            }
        for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            if(k != i && k != j && dis[i][j] >= dis[i][k] + dis[k][j]){
                vis[i][j] = 1;
                //cout<<i<<" to "<<j<<endl;
                dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            if( vis[i][j] && dis[i][j] == mat[i][j] ) ans += 1;
            if(dis[i][j] < mat[i][j]) flag = 1;
        }
        if(flag) printf("Case %d: impossible\n", ca++);
        else printf("Case %d: %d\n", ca++, n*(n-1) - ans);
    }
}
