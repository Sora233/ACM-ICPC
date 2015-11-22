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
struct ps{
    int x,y,t;
    ps(){t=0;}
    ps(int _x,int _y,int _t){x=_x,y=_y,t=_t;}
}s1,s2;
const int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
char map[205][205];
int tis[205][205];
int n,m;
bool vis[205][205];
void bfs(ps s){
    memset(vis,0,sizeof(vis));
    queue<ps>q;
    vis[s.y][s.x]=1;
    q.push(s);
    while(!q.empty()){
        ps now=q.front();q.pop();
        for(int i=0;i<4;++i){
            int nx=now.x+dir[i][0],ny=now.y+dir[i][1],nt=now.t+1;
            if(nx>=1&&nx<=m&&ny>=1&&ny<=n&&map[ny][nx]!='#'&&map[ny][nx]!='Y'&&map[ny][nx]!='M'&&!vis[ny][nx]){
                    vis[ny][nx]=1;
                    tis[ny][nx]+=nt*11;
                    q.push(ps(nx,ny,nt));
            }
        }
    }
}
int main(){
    while(scanf("%d %d%*c",&n,&m)!=EOF){
        memset(tis,0,sizeof(tis));
        for(int i=1;i<=n;++i) {
                gets(map[i]+1);
                for(int j=1;j<=m;++j){
                    if(map[i][j]=='Y') s1.y=i,s1.x=j,s1.t=0;
                    if(map[i][j]=='M') s2.y=i,s2.x=j,s2.t=0;
                }
        }
        bfs(s1);
        bfs(s2);
        int ans=0xfffffff;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(map[i][j]=='@'&&vis[i][j]) ans=min(ans,tis[i][j]);
            }
        }
        printf("%d\n",ans);
    }
}
