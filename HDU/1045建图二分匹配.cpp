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
struct edg{
    int a,b;//ппап
}map[5][5];
vector<int>G[30];
char nmap[10][10];
int N,ME;
int used[30],match[30];
void getmap(){
    int cor=1;
    for(int i=1;i<=N;++i,++cor)
        for(int j=1;j<=N;++j){
        if(j==1) while(nmap[i][j]=='X') j+=1;
        if(j>N) continue;
        if(nmap[i][j]=='X'){
            int l;
            for(l=j;l<=N;++l) if(nmap[i][l]!='X') break;
            if(l>N) break;
            cor+=1;
        }
        map[i][j].a=cor;
    }
    ME=max(cor,ME);
    cor=1;
    for(int i=1;i<=N;++i,++cor)
    for(int j=1;j<=N;++j){
        if(j==1) while(nmap[j][i]=='X') j+=1;
        if(j>N) continue;
        if(nmap[j][i]=='X'){
            int l;
            for(l=j;l<=N;++l) if(nmap[l][i]!='X') break;
            if(l>N) break;
            cor+=1;
        }
        map[j][i].b=cor;
    }
    ME=max(cor,ME);
}
void tovec(){
    for(int i=1;i<=ME;++i) G[i].clear();
    for(int i=1;i<=N;++i)
    for(int j=1;j<=N;++j){
        if(nmap[i][j]!='X') {
                G[map[i][j].a].pb(map[i][j].b);
        }
    }
}
bool find(int x){
    for(int i=0;i<G[x].size();++i){
        int u=G[x][i];
        if(!used[u]){
            used[u]=1;
            if(match[u]==-1||find(match[u])){
                match[u]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    while(scanf("%d%*c",&N)!=EOF&&N){
        ME=0;
        memset(match,-1,sizeof(match));
        for(int i=1;i<=N;++i)
            gets(nmap[i]+1);
        getmap();
        tovec();
        int ans=0;
        for(int i=1;i<=ME;++i){
            memset(used,0,sizeof(used));
            if(find(i)) ans+=1;
        }
        printf("%d\n",ans);
    }
}
