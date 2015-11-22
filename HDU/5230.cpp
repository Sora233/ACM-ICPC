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
#include<cctype>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
const int mod=998244353;
int dp[100005];
inline int readint(){
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    int x=0;
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}
int buf[10];
inline void writeint (int i){
    int p=0;
    if(i==0) p+=1;
    else while(i){
        buf[p++]=i%10;
        i/=10;
    }
    for(int j=p-1;j>=0;--j) putchar('0'+buf[j]);
    printf("\n");
}
int main(){
    int T=readint();
    while(T--){
        int n=readint(),c=readint(),l=readint(),r=readint();
        l-=c,r-=c,n-=1;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;++i){
            for(int j=min(r,i*(i-1)/2);j>=0;--j){
                if(j+i<=r) dp[i+j]=(dp[i+j]+dp[j])%mod;
            }
        }
        int ans=0;
        for(int i=l;i<=r;++i){
            ans=(ans+dp[i])%mod;
        }
        writeint(ans);
    }
}
