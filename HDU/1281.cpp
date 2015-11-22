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
bool map[105][105];
int H,W,K;
int used[105],match[105];
int find(int x){
    for(int i=1;i<=W;++i){
        if(!map[x][i]) continue;
        if(!used[i]){
            used[i]=1;
            if(match[i]==-1||find(match[i])){
                match[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int solve(){
    int res=0;
    memset(match,-1,sizeof(match));
    for(int i=1;i<=H;++i){
        memset(used,0,sizeof(used));
        if(find(i)) res+=1;
    }
    return res;
}
int main(){
    int cas=1,a,b;
    while(scanf("%d%d%d",&H,&W,&K)!=EOF){
        memset(map,0,sizeof(map));
        for(int i=0;i<K;++i){
            scanf("%d%d",&a,&b);
            map[a][b]=1;
        }
        int Maxmatch=solve(),ans=0;
        for(int i=1;i<=H;++i){
            for(int j=1;j<=W;++j){
                if(map[i][j]){
                    map[i][j]=0;
                    if(solve()!=Maxmatch) ans+=1;
                    map[i][j]=1;
                }
            }
        }
        printf("Board %d have %d important blanks for %d chessmen.\n",cas++,ans,Maxmatch);
    }
}
