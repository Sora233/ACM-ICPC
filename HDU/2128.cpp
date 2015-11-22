#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
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
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct node{
    int x,y;
    int t,exp;
    char mp[10][10];
    bool operator<(node a)const{return t>a.t;}
}s,e;
int n,m;
int vis[10][10][50];
int bfs(){
	node now;
    memset(vis,0,sizeof(vis));
    priority_queue<node>q;
    s.exp=s.t=0;
    q.push(s);
    vis[s.y][s.x][s.exp]+=1;
    while(!q.empty()){
        now=q.top();
        for(int i=0;i<4;++i){
        	int &x=now.x,&y=now.y,&t=now.t,&exp=now.exp;
			x+=dir[i][0];
            y+=dir[i][1];
            t+=1;
            char &p=now.mp[y][x];
            if(x<1||y<1||x>m||y>n||vis[y][x][exp]>3){
            	now=q.top();
            	continue;
            }
            if(p!='X'){
                if(p>='1'&&p<='9') {
                        exp+= p - '0';
                        now.mp[y][x]='.';
                }
                vis[y][x][exp]+=1;
                q.push(now);
                if(x==e.x&&y==e.y) return t;
            }
            else {
                if(exp==0) {
                	now=q.top();
               		continue;
         	    }
                now.mp[y][x]='.';
                exp-=1;
                t+=1;
                vis[y][x][exp]+=1;
                q.push(now);
                if(x==e.x&&y==e.y) return t;
            }
            now=q.top();
        }
        q.pop();
    }
    return -1;
}
int main(){
    while(scanf("%d%d%*c",&n,&m)!=EOF&&(n+m)){
        for(int i=1;i<=n;++i){
            gets(s.mp[i]+1);
            for(int j=1;j<=m;++j){
                if(s.mp[i][j]=='S') s.y=i,s.x=j;
                if(s.mp[i][j]=='D') e.y=i,e.x=j;
            }
        }
        printf("%d\n",bfs());
    }
}
