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
int dp[10][3];//dp[i][j]，i代表数字的位数，j代表状况
//dp[i][0],表示不存在不吉利数字
//dp[i][1],表示不存在不吉利数字，且最高位为2
//dp[i][2],表示存在不吉利数字
void ints(){
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=7;++i){
        dp[i][0]=dp[i-1][0]*9-dp[i-1][1]; //第一位不放4 且减去放6且前一位是2的
        dp[i][1]=dp[i-1][0]; //在开头放一个2
        dp[i][2]=dp[i-1][2]*10+dp[i-1][1]+dp[i-1][0];
    }
}
int gn(int p){
    int res=0,len=0,buf[10]={0},tmp=p,flag=0;
    while(p){
        buf[++len]=p%10;
        p/=10;
    }
    for(int i=len;i>=1;--i){
        res+=dp[i-1][2]*buf[i];
        if(flag) res+=dp[i-1][0]*buf[i];
        else {
            if(buf[i]>4) res+=dp[i-1][0];
            if(buf[i+1]==6&&buf[i]>2) res+=dp[i][1];
            if(buf[i]>6) res+=dp[i-1][1];
        }
        if(buf[i]==4||(buf[i+1]==6&&buf[i]==2)) flag=1;
    }
    return tmp-res;
}
int main(){
    ints();
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&(n+m)){
        printf("%d\n",gn(m+1)-gn(n));
    }
}
