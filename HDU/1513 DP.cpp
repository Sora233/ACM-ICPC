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
/*求把一个字符串转化成回文需要最少的操作次数。
把这个字符串反过来写一遍，然后这两个字符串求最长公共子序列。
最后字符串长度-公共子序列长度就是最少的操作数。
*/
int len;
int dp[5][5005]; //dp[i][j]表示a到i b到j的LCS 用到滚动数组
char a[5005],b[5005];
int LCS(){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=len;++i){
        for(int j=1;j<=len;++j){
            if(a[i]==b[j]) dp[i%2][j]=dp[(i-1)%2][j-1]+1;
            else dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
        }
    }
    return dp[len%2][len];
}
int main(){
    while(scanf("%d%*c",&len)!=EOF){
        scanf("%s",a+1);
        for(int i=len;i>0;--i) b[len-i+1]=a[i];
        cout<<len-LCS()<<endl;
    }
}
