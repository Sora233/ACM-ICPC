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
int dp[2005][2005]; //dp[i][2*j]表示前i件物品选j对的最小代价
int num[2005]={0};
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		if(j)dp[i][j]=0xfffffff;
		else dp[i][j]=0;
        for(int i=1;i<=n;++i) scanf("%d",&num[i]);
        sort(num+1,num+n+1);
        for(int i=2;i<=n;++i){
            for(int j=1;2*j<=i;++j){
                dp[i][j]=min(dp[i-2][j-1]+(num[i]-num[i-1])*(num[i]-num[i-1]),dp[i-1][j]);
            }
        }
        printf("%d\n",dp[n][k]);
    }
}
