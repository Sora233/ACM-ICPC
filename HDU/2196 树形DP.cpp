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
int fa[N]={-1,-1,1};  // i�ĸ��ڵ�Ϊfa[i]
int longs[N]; //longs[i]��ʾ��iΪ�������е������
int longf[N]; //longf[i]��ʾ��iΪ���ӵ����е������
int longid[N];
vector<node>G[N];
void dfs(int root){
    int u,w;
    for(int i=0;i<G[root].size();++i){
        u=G[root][i].next,w=G[root][i].cost; //u��i���ӽڵ�
        if(u==fa[root]) continue; //���������׽��
        dfs(u); //�ȵݹ鵽���ӽڵ�
        longs[root]=max(longs[root],longs[u]+w);
    }
    //cout<<root<<"�����ڵ����Զ����Ϊ"<<longs[root]<<endl;
}
void dfs1(int root){  //son��root���ӽڵ�
    int u,w;
    for(int i=0;i<G[root].size();++i){ // root�����ڵ�ľ���
        if(G[root][i].next==fa[root]) { // u��root�ĸ����
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
