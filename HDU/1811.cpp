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
int seed[10005];
int find(int x){return seed[x]<0?x:seed[x]=find(seed[x]);}
bool join(int a,int b){
    a=find(a),b=find(b);
    if(a!=b) seed[b]=a;
    else return 0;
    return 1;
}
vector<int>G[10005];
int in[10005];
struct edg{
    int u,v;
    char op;
}eg[20005];
int main(){
    int n,m,a,b;
    char op;
    while(scanf("%d %d",&n,&m)!=EOF){
        int num=n,flag=1;
        memset(in,0,sizeof(in));
        memset(seed,-1,sizeof(seed));
        for(int i=0;i<=n;++i) G[i].clear();
        for(int i=0;i<m;++i){
            scanf("%d %c %d",&eg[i].u,&eg[i].op,&eg[i].v);
            if(eg[i].op=='='&&join(eg[i].u,eg[i].v))
                num-=1;
        }
        for(int i=0;i<m;++i){
            if(eg[i].op=='=') continue;
            int u=find(eg[i].u),v=find(eg[i].v);
            //if(u==v) { flag=0; break; }
            if(eg[i].op=='>') G[u].pb(v),in[v]+=1;
            else if(eg[i].op=='<') G[v].pb(u),in[u]+=1;
        }
        if(!flag) { puts("CONFLICT"); continue; }
        queue<int>q;
        for(int i=0;i<n;++i) if( !in[i]&&find(i)==i) q.push(i);
        while(!q.empty()){
            if(q.size()>1){ flag=-1; }
            int now=q.front();q.pop(); num-=1;
            for(int i=0;i<G[now].size();++i)
                if((--in[G[now][i]])==0) q.push(G[now][i]);
        }
        if(num) puts("CONFLICT");
        else if(flag==-1) puts("UNCERTAIN");
        else puts("OK");
    }
}
