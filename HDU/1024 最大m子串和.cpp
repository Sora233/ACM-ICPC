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
const int MAXN = 1000005;
int dp[MAXN][2]; //dp[j][0]表示前j个分成i段并以num[j]结尾的最大值 dp[j][1]表示前j个分成i段的最大值
int num[MAXN];
int main(){
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF){
        int ans=-0xfffffff;
        for(int i=1;i<=n;++i) scanf("%d",&num[i]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;++i){
            ans=-0xfffffff;
            for(int j=i;j<=n;++j){
                dp[j][0]=max(dp[j-1][0]+num[j],dp[j-1][1]+num[j]);
                dp[j-1][1]=ans;
                ans=max(ans,dp[j][0]);
            }
        }
        printf("%d\n",ans);
    }
}
