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
float dp[20005]; //dp[j]表示抢j元的最大逃脱概率
float risk[105];
int val[105];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        float safe;
        int n,up=0;
        scanf("%f%d",&safe,&n);
        safe=1-safe;
        for(int i=1;i<=n;++i) {
            scanf("%d%f",&val[i],&risk[i]);
            up+=val[i];
            risk[i]=1-risk[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;++i){
            for(int j=up;j>=val[i]; --j){
                dp[j]=max(dp[j],dp[j-val[i]]*risk[i]); //dp[i][j]=max(dp[i-1][j],dp[i-1][j-val[i]]*risk[i]);
            }
        }
        for(int i=up;i>=0;--i){
            if(dp[i]>=safe) {
                printf("%d\n",i);
                break;
            }
        }
    }
}
