#include<stdio.h>
#include<stack>
#include<queue>
#include<string.h>
using namespace std;
char maze[101][101];
bool visit[101][101];
int times[101][101];
int M,N,turn,flag;
int direct[4][2]={{0,1},{-1,0},{0,-1},{1,0}}; // ср ио вС об 
struct node{
	int x,y;
};
node start,end;
queue<node>line;
void BFS(node start,node end){
	int Time;
    node now,next;
	line.push(start);
	visit[start.y][start.x]=1;
	while(!line.empty()){
		now=line.front();
		line.pop();
		Time=times[now.y][now.x]+1;
		for(int i=0;i<4;i++){
		    	next.x=now.x+direct[i][0];
		    	next.y=now.y+direct[i][1];
		    while(next.x>=1&&next.x<=N&&next.y>=1&&next.y<=M&&maze[next.y][next.x]=='.'){
			    if(!visit[next.y][next.x]){
				if(next.x==end.x&&next.y==end.y&&Time<=turn+1){
		        	flag=1;
			        return;
		        }
		        times[next.y][next.x]=Time;
		        visit[next.y][next.x]=1;
		        line.push(next);
		        }
		    next.x+=direct[i][0];
		    next.y+=direct[i][1];
		    }
     	}
	}
}
int main(){
	//freopen("1728.in","r",stdin);
	int T,i;
	scanf("%d%*c",&T);
	while(T--){
		scanf("%d%d%*c",&M,&N);
		flag=0;
		for(i=1;i<=M;i++)
		gets(maze[i]+1);
		while(line.size()) line.pop();
		memset(visit,0,sizeof(visit));
		memset(times,0,sizeof(times));
		scanf("%d%d%d%d%d",&turn,&start.x,&start.y,&end.x,&end.y);
		if(start.x==end.x&&start.y==end.y) {
			printf("yes\n");
			continue;
		}
			BFS(start,end);
			if(flag) printf("yes\n");
		else printf("no\n");
}
}
