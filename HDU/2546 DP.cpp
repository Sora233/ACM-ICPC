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
int dp[1005];
int val[1005];
int main(){
    int n,m;
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=1;i<=n;++i) scanf("%d",&val[i]);
        sort(val+1,val+1+n);
        scanf("%d",&m);
        if(m<5){
            printf("%d\n",m);
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n;++i){
            for(int j=m-5;j>=val[i];--j){
                dp[j]=max(dp[j],dp[j-val[i]]+val[i]);
            }
        }
        printf("%d\n",m-dp[m-5]-val[n]);
    }
}
