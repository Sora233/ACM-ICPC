#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<string>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
vector<int>G[105];
int match[105],used[105];
bool find(int x){
    for(int i=0;i<G[x].size();++i){
        int t=G[x][i];
        if(!used[t]){
            used[t]=1;
            if(match[t]==-1||find(match[t])){
                match[t]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int n,m,p;
    while(scanf("%d",&n)!=EOF&&n){
        scanf("%d",&m);
        for(int i=0;i<=n;++i) G[i].clear();
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                scanf("%d",&p);
                if(p){
                    G[i].pb(j);
                //    G[j].pb(i);
                }
            }
        }
        int ans=0;
        memset(match,-1,sizeof(match));
        for(int i=1;i<=n;++i){
            memset(used,0,sizeof(used));
            if(find(i)) ans+=1;
        }
        printf("%d\n",ans);
    }
}
