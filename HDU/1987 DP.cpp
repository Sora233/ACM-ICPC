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
int mze[105][105];
int dp[105][105];
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                scanf("%d",&mze[i][j]);
        dp[1][1]=1;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                int step=mze[i][j];
                for(int k=0;k<=step;++k){
                    for(int l=step-k;l>=0;--l){
                        if((k||l)&&k+i<=n&&k+i>=1&&l+j>=1&&l+j<=m) dp[i+k][j+l]=(dp[i+k][j+l]+dp[i][j])%10000;
                    }
                }
            }
        }
        cout<<dp[n][m]%10000<<endl;
    }
}
