#include<stdio.h>
#include<string.h>
#include<cmath>
#include<iostream>
using namespace std;
struct node{
	int x,y;
};
int N,M,T,flag; // ÐÐ ÁÐ 
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
node start,end;
char maze[8][8];
bool visit[8][8];
void dfs(node s,int t){
	if(flag) return;
	int temp=t-abs(s.x-end.x)-abs(s.y-end.y);
	if(temp<0||temp&1) return;
	node now=s,next;
	if(maze[now.y][now.x]=='D'&&!t) flag=1;
	for(int i=0;i<4;i++){
		if(flag) return;
		next.x=now.x+dir[i][0];
		next.y=now.y+dir[i][1];
		if(next.x>=1&&next.x<=M&&next.y>=1&&next.y<=N&&!visit[next.y][next.x])
			if(maze[next.y][next.x]=='.'||maze[next.y][next.x]=='D'){
				visit[next.y][next.x]=1;
				dfs(next,t-1);
				visit[next.y][next.x]=0;
				if(flag) return;
			}
	}
}
int main(){
	//freopen("1010.in","r",stdin);
	cin>>N>>M>>T;
	while(N||M||T){
		flag=0;
		int count;
		memset(maze,0,sizeof(maze));
		memset(visit,0,sizeof(visit));
		for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
		cin>>maze[i][j];
		if(maze[i][j]=='S'){
			start.x=j;
			start.y=i;
		}
		else if(maze[i][j]=='D'){
			end.x=j;
			end.y=i;
		}
		else if(maze[i][j]=='.') count++;
	}
    }
		if(count+1<T) {
			cout<<"NO"<<endl;
			continue;
		}
		visit[start.y][start.x]=1;
		dfs(start,T);
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		cin>>N>>M>>T;
	}
}
