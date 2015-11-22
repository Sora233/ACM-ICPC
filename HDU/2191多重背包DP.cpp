#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<string>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
int val[105],wei[105],t[105];
int dp[105];
int main(){
    int T,a,b,c,V,m,i,j,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&V,&m);
        for(i=1;i<=m;++i) scanf("%d %d %d",&wei[i],&val[i],&t[i]);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=m;++i)
            for(k=0;k<t[i];++k)
                for(j=V;j>=wei[i];--j){
                    if(dp[j-wei[i]]+val[i]>dp[j]) dp[j]=dp[j-wei[i]]+val[i];
                }
        printf("%d\n",dp[V]);
    }
}
