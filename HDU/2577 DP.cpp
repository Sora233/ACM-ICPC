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
int dp[105][2]; //dp[i][0]表示关灯时打完第i个字母的最小操作数
int main(){    //dp[i][1]表示开灯时打完第i个字母的最小操作数
    int T;
    char s[105];
    scanf("%d%*c",&T);
    while(T--){ //注意初始状态
        dp[0][0]=0;
        dp[0][1]=1;
        gets(s+1);
        int len=strlen(s+1);
        for(int i=1;i<=len;++i){
            if(s[i]>='a'&&s[i]<='z'){
                dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]+2);
                dp[i][1]=min(dp[i-1][1]+2,dp[i-1][0]+2);
            }
            else if(s[i]>='A'&&s[i]<='Z'){
                dp[i][0]=min(dp[i-1][0]+2,dp[i-1][1]+2);
                dp[i][1]=min(dp[i-1][1]+1,dp[i-1][0]+2);
            }
        }
        //puts(s+1);
        dp[len][0]=min(dp[len][0],dp[len][1]+1);
        //printf("dp[%d][0]=%d,dp[%d][1]=%d\n",len,dp[len][0],len,dp[len][1]+1);
        printf("%d\n",dp[len][0]);
    }
}
