#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
char map[15][15][2];
bool vis[15][15][2];
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m,t;//n––m¡– 
struct node{
	int x,y,f,t;
	bool operator == (node p) const {
		return x==p.x&&y==p.y&&f==p.f;
	}
}s,e;
void mark(node p){
	vis[p.y][p.x][p.f]=1;
}
bool moveok(node p){
	if(p.x<0||p.y<0||p.x>=m||p.y>=n||map[p.y][p.x][p.f]=='*'||vis[p.y][p.x][p.f]) return 0;
	return 1;
}
bool bfs(){
	s.t=0;
	node now,next;
	queue<node>line;
	line.push(s);
	mark(s);
	while(!line.empty()){
		now=line.front();
		line.pop();
		for(int i=0;i<4;++i){
			next=now;
			next.t+=1;
			next.x+=dir[i][0],next.y+=dir[i][1];
			if(next.t>t) continue;
			if(moveok(next)){
				if(map[next.y][next.x][next.f]=='#') {
					next.f=!next.f;
					vis[next.y][next.x][0]=vis[next.y][next.x][1]=1;
				}
				else {
					mark(next);
				}
				line.push(next);
				if(next==e) return 1;
			}
		}
	}
	return 0;
}
int main(){
	int T;
	scanf("%d%*c",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d %d %d%*c",&n,&m,&t);
		for(int l=0;l<2;++l){
			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j){
					scanf("%c",&map[i][j][l]);
					if(map[i][j][l]=='S') s.x=j,s.y=i,s.f=l;
					else if(map[i][j][l]=='P') e.x=j,e.y=i,e.f=l;
				}
				getchar();
			}
			if(!l)getchar();
		}
		for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			if(map[i][j][0]=='#'){
				if(map[i][j][1]=='#'||map[i][j][1]=='*') map[i][j][0]='*';
			}
			if(map[i][j][1]=='#'){
				if(map[i][j][0]=='#'||map[i][j][0]=='*') map[i][j][1]='*';
			}
		}
		printf("%s\n",bfs()?"YES":"NO");
	}
}

