#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<string>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
int map[25][25];
int dp[25][25];//走i步到j的方法数
int n,m;
int solve(int s,int e,int k){
    memset(dp,0,sizeof(dp));
    dp[0][s]=1;
    for(int l=1;l<=k;++l)
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
        if(map[i][j]) dp[l][j]=(dp[l][j]+dp[l-1][i])%1000;
    return dp[k][e];
}
int main(){
    int T,a,b,c,s,e,k;
    while(scanf("%d%d",&n,&m)!=EOF&&(n+m)){
        memset(map,0,sizeof(map));
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&a,&b);
            map[a+1][b+1]=1;
        }
        scanf("%d",&T);
        while(T--){
            scanf("%d%d%d",&s,&e,&k);
            printf("%d\n",solve(s+1,e+1,k));
        }
    }
}
