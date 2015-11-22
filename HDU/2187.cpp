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
int val[1005],item[1005];
int main(){
    int T;
    cin>>T;
    while(T--){
        int money,kind;
        cin>>money>>kind;
        for(int i=1;i<=kind;++i){
            cin>>item[i]>>val[i];
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=kind;++i){
            for(int j=item[i];j<=money;++j)
                dp[j]=max(dp[j],dp[j-item[i]]+val[i]);
        }
        cout<<dp[money]<<endl;
    }
}
