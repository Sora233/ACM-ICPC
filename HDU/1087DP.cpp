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
int num[1005];
int dp[1005]; //dp[i]表示到i的最大价值
int main(){   // dp[i]=max(dp[j])+num[i]; 1<=j<i&&num[i]>num[j]
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        int ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i)
            scanf("%d",&num[i]);
        for(int i=1;i<=n;++i){
            for(int j=0;j<i;++j){
                if(num[i]>num[j]) {
                        dp[i]=max(dp[j]+num[i],dp[i]);
                        ans=max(ans,dp[i]);
                }
            }
        }
        printf("%d\n",ans);
    }
}
