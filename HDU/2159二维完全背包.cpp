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
int val[105],cost[105];
int dp[105][105]; //dp[i][j]表示 有 i耐久 杀 j 个怪的最大经验值
int main(){
    int n,m,k,s; //经验 耐久 怪物种数 最多杀怪数
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF){
        int ans=0xfffffff;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=k;++i) scanf("%d%d",&val[i],&cost[i]);
        for(int l=1;l<=k;++l){
            for(int i=cost[l];i<=m;++i){
                for(int j=1;j<=s;++j){
                    dp[i][j]=max(dp[i][j],dp[i-cost[l]][j-1]+val[l]);
                    if(dp[i][j]>=n) ans=min(ans,i);
                }
            }
        }
        printf("%d\n",dp[m][s]<n? -1:m-ans);
    }
}
