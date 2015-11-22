#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
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
#define LL long long int
using namespace std;
int Map[50][2005];
int dp[50][2005];
int n,m;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                scanf("%d",&Map[i][j]);
        for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) dp[i][j]=-0xfffffff;
        dp[1][1]=Map[1][1];
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(i+1<=n) dp[i+1][j]=max(dp[i][j]+Map[i+1][j],dp[i+1][j]);
                if(j+1<=m) dp[i][j+1]=max(dp[i][j+1],dp[i][j]+Map[i][j+1]);
                for(int k=2;k*j<=m;++k){
                    dp[i][k*j]=max(dp[i][k*j],dp[i][j]+Map[i][k*j]);
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
}
