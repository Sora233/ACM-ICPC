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
int sqr[105][105]={0};
int dp[105][105];//dp[j]表示有j天 前i个科目的最大价值
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&(n+m)){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                scanf("%d",&sqr[i][j]);
        for(int i=1;i<=n;++i){
            for(int j=m;j>=1;--j){
                for(int l=1;l<=m;++l){
                    if(j>=l) dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j-l]+sqr[i][l]));
                    else break;
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
}
