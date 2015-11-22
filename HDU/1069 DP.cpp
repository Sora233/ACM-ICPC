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
struct cub{
    int x,y,z;
}cb[1005];
int dp[1005];
int cort;
void add(int a,int b,int c){
    cb[cort].x=a;
    cb[cort].y=b;
    cb[cort].z=c;
    cort+=1;
}
bool cmp(cub a, cub b){
    if(a.x!=b.x) return a.x>b.x;
    else if(a.y!=b.y) return a.y>b.y;
    return a.z>b.z;
}
int main(){
    int n,a,b,c,ca=1;
    cb[0].x=cb[0].y=0xfffffff,cb[0].z=0;
    while(scanf("%d",&n)!=EOF&&n){
        int ans=0;
        memset(dp,0,sizeof(dp));
        cort=1;
        for(int i=0;i<n;++i){
            scanf("%d %d %d",&a,&b,&c);
            add(a,b,c);
            add(a,c,b);
            add(b,a,c);
            add(b,c,a);
            add(c,a,b);
            add(c,b,a);
        }
        sort(cb+1,cb+cort,cmp);
        for(int i=1;i<cort;++i){
            for(int j=0;j<i;++j){
                if(cb[i].x<cb[j].x&&cb[i].y<cb[j].y){
                    dp[i]=max(dp[i],dp[j]+cb[i].z);
                }
                ans=max(ans,dp[i]);
            }
        }
        printf("Case %d: maximum height = %d\n",ca++,ans);
    }
}
