#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
int dp[105];//dp[i]表示去i城市的最大价值
int val[105];
int path[105];
vector<int>G[105];
int n,m;
void print(int e){
    if(path[e]){
        print(path[e]);
    }
    if(e==n+1) printf("->1\n");
    else if(e!=1) printf("->%d",e);
}
int main(){
    int T,ca=1;
    scanf("%d",&T);
    while(T--){
        memset(dp,0,sizeof(dp));
        memset(path,0,sizeof(path));
        scanf("%d",&n);
        val[n+1]=0;
        G[n+1].clear();
        for(int i=1;i<=n;++i){
            G[i].clear();
            scanf("%d",&val[i]);
        }
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            G[b].pb(a);
        }
        for(int i=2;i<=n+1;++i){
            int nex=-1;
            for(int j=0;j<G[i].size();++j){
                int u=G[i][j]; // u 可以通往 i
                if(dp[i]<dp[u]+val[i]) dp[i]=dp[u]+val[i],nex=u;
            }
            if(nex!=-1) path[i]=nex;
        }
        printf("CASE %d#\npoints : %d\ncircuit : 1",ca++,dp[n+1]);
        print(n+1);
        if(T) printf("\n");
    }
}
