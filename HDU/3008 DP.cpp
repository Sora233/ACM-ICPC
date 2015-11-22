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
int kind,res,hurt,T,ans;
int dp[105][255]; //dp[i][j] 剩余 i秒 和j魔法造成的最大伤害
int cost[105],hp[105];
int dfs(int t,int mp){
    if(dp[t][mp]) return dp[t][mp];
    int ma=0;
    for(int i=1;i<=kind;++i){
        if(t) {
            if(mp>=cost[i]) ma=max(ma,hp[i]+dfs(t-1,(mp+res-cost[i]>100? 100 : mp+res-cost[i])));
        }
        else {
             if(mp>=cost[i]) ma=max(ma,hp[i]);
        }
    }
    if(ma>=100) ans=max(ans,t);
    return dp[t][mp]=ma;
}
int main(){
    cost[1]=0,hp[1]=1;
    while(scanf("%d%d%d",&kind,&res,&hurt)!=EOF&&(kind+res+hurt)){
        T=(100%hurt)? 100/hurt+1 : 100/hurt;
        memset(dp,0,sizeof(dp));
        kind+=1;
        for(int i=2;i<=kind;++i) scanf("%d%d",&cost[i],&hp[i]);
        dp[T][100]=0;
        ans=0;
        dfs(T,100);
        cout<<ans<<endl;
    }
}
