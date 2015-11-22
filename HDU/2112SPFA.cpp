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
map<string,int>mp;
vector<pii >G[10005];
int dis[10005],cort=1;
bool vis[10005];
char st[50],en[50];
int n;
int spfa(int s){
    queue<int>q;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<cort;++i) dis[i]=0xfffffff;
    dis[s]=0;
    q.push(s);vis[s]=1;
    while(!q.empty()){
        int now=q.front();q.pop();vis[now]=0;
        for(int i=0;i<G[now].size();++i){
            int nex=G[now][i].first,w=G[now][i].second;
            if(dis[now]+w<dis[nex]){
                dis[nex]=dis[now]+w;
                if(vis[nex]==0){
                        q.push(nex);
                        vis[nex]=1;
                }
            }
        }
    }
    if(dis[mp[en]]==0xfffffff) return -1;
    else return dis[mp[en]];
}
int main(){
    while(scanf("%d%*c",&n)!=EOF&&n!=-1){
        mp.clear();
        for(int i=0;i<=200;++i) G[i].clear();
        cort=1;
        scanf("%s%s",st,en);
        char a[50],b[50];
        int dis;
        for(int i=1;i<=n;++i){
            scanf("%s%s%d",a,b,&dis);
            if(mp[a]==0) mp[a]=cort++;
            if(mp[b]==0) mp[b]=cort++;
            G[mp[a]].pb(make_pair(mp[b],dis));
            G[mp[b]].pb(make_pair(mp[a],dis));
        }
        if(mp[st]==0||mp[en]==0) printf("-1\n");
        else printf("%d\n",spfa(mp[st]));
    }
}

