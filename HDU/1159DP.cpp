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
int dp[500][500]; //dp[i][j] 表示ai和bj的最长共工子序列
int main(){       // if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
    string a,b;   // else dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    while(cin>>a>>b){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<a.size();++i)
        for(int j=0;j<b.size();++j){
            if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
            else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
        cout<<dp[a.size()][b.size()]<<endl;
    }
}
