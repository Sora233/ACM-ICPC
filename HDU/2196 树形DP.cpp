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
const int N=10005;
struct node{
    int next,cost;
    node(){};
    node(int a,int b){
        next=a,cost=b;
    }
};
int fa[N]={-1,-1,1};  // i的父节点为fa[i]
int longs[N]; //longs[i]表示以i为根的树中的最长距离
int longf[N]; //longf[i]表示以i为儿子的树中的最长距离
int longid[N];
vector<node>G[N];
void dfs(int root){
    int u,w;
    for(int i=0;i<G[root].size();++i){
        u=G[root][i].next,w=G[root][i].cost; //u是i的子节点
        if(u==fa[root]) continue; //不搜索父亲结点
        dfs(u); //先递归到儿子节点
        longs[root]=max(longs[root],longs[u]+w);
    }
    //cout<<root<<"到根节点的最远距离为"<<longs[root]<<endl;
}
void dfs1(int root){  //son是root的子节点
    int u,w;
    for(int i=0;i<G[root].size();++i){ // root到父节点的距离
        if(G[root][i].next==fa[root]) { // u是root的父结点
            u=G[root][i].next,w=G[root][i].cost;
            break;
        }
    }
    if(u!=-1) longf[root]=max(longf[root],longf[u]+w);
    for(int i=0;i<G[root].size();++i){

    }
}
int main(){
    int n,a,b;
    while(scanf("%d",&n)!=EOF){
        for(int i=2;i<=n;++i){
            scanf("%d%d",&a,&b);
            G[i].pb(node(a,b));
            G[a].pb(node(i,b));
            fa[i]=a;
        }
        memset(longs,0,sizeof(longs));
        dfs(1);
        dfs1(1);
    }
}
