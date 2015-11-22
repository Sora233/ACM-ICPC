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
using namespace std;
const int MN=105;
vector<pii >G[MN];
int vis[105],dis[105];
int city,road;//´Ó1×ßµ½city
void ints(){
    for(int i=0;i<=city;++i){
        vis[i]=0;
        dis[i]=0xffffff;
        G[i].clear();
    }
}
void spfa(int x){
    queue<int>line;
    vis[x]=1;
    line.push(x);
    dis[x]=0;
    while(!line.empty()){
        int now=line.front();line.pop();
        vis[now]=0;
        for(int i=0;i<G[now].size();++i){
            int next=G[now][i].first,w=G[now][i].second;
            if(dis[next]>w+dis[now]){
                dis[next]=w+dis[now];
                if(!vis[next]){
                    line.push(next);
                    vis[next]=1;
                }
            }
        }
    }
    cout<<dis[city]<<endl;
}
int main(){
    int a,b,c;
    while(cin>>city>>road&&city&&road){
        ints();
        for(int i=0;i<road;++i){
            cin>>a>>b>>c;
            G[a].pb(make_pair(b,c));
            G[b].pb(make_pair(a,c));
        }

        spfa(1);
    }
}
