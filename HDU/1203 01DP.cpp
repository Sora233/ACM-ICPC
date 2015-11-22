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
double dp[10005]; //dp[j]表示有j万元得不到offer的最小概率
double gailv[10005];
int cost[10005];
int main(){
    int n,m; //有n万元 m个学校
    while(scanf("%d%d",&n,&m)!=EOF&&(n+m)){
        for(int i=0;i<=10005;++i) dp[i]=1;
        for(int i=1;i<=m;++i) {
                scanf("%d %lf",&cost[i],&gailv[i]);
                gailv[i]=1-gailv[i];
        }
        for(int i=1;i<=m;++i){
            for(int j=n;j>=cost[i];--j)
                dp[j]=min(dp[j],dp[j-cost[i]]*gailv[i]);
        }
        printf("%.1f%%\n",(1-dp[n])*100);
    }
}
