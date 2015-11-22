#include<cstring>
#include<cstdio>
#include<vector>
#define pb push_back
using namespace std;
int map[1005][1005];
struct eg{
    int u,v;
    eg(){}
    eg(int _u,int _v){u=_u,v=_v;}
};
vector<eg>G[105];
int Ab(int x){return x<0?-x:x;}
int seed[2000040];
int find(int x){return seed[x]<0?x:seed[x]=find(seed[x]);}
int join(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return 0;
    if(seed[a]>seed[b]) seed[b]+=seed[a],seed[a]=b;
    else seed[a]+=seed[b],seed[b]=a;
    return 1;
}
int main(){
    int T,ca=1;
    scanf("%d",&T);
    while(T--){
        int n,m,cnt=0;
        for(int i=0;i<105;++i) G[i].clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                scanf("%d",&map[i][j]);
                if(i!=1){
                    int c=Ab(map[i][j]-map[i-1][j]);
                    G[c].pb(eg(m*(i-1)+j,m*(i-2)+j));
                }
                if(j!=1){
                    int c=Ab(map[i][j]-map[i][j-1]);
                    G[c].pb(eg(m*(i-1)+j,m*(i-1)+j-1));
                }
            }
        }
        memset(seed,-1,sizeof(seed));
        int ans=0;
        for(int c=0;c<105;++c){
            for(int i=0;i<G[c].size();++i) {
                if(join(G[c][i].u,G[c][i].v)) ans+=c;
            }
		}
        printf("Case #%d:\n%d\n",ca++,ans);
    }
}
