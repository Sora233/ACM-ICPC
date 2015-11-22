#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int num[100005],len;
int dp[100005];
int main(){
    int T,ca=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&len);
        for(int i=1;i<=len;++i){
            scanf("%d",&num[i]);
            num[i]-=i;
        }
        dp[0]=-0xfffffff;
        int cnt=1;
        for(int i=1;i<=len;++i){
            int p=upper_bound(dp,dp+cnt,num[i]) - dp;
            if(p==cnt) dp[cnt++]=num[i];
            else dp[p]=num[i];
        }
        printf("Case #%d:\n%d\n",ca++,len - cnt+1);
    }
}
