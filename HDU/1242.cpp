#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
int M,N,flag; //行 列 
char maze[201][201];
int visit[201][201];
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}}; //右 上 左 下 
struct node{
	int x,y;
};
node start,end,ans;
void Find(node *s,node *e){
	for(int i=1;i<=M;i++)
	for(int j=1;j<=N;j++)
	if(maze[i][j]=='r'){
		s->x=j;
		s->y=i;
	}
	else if(maze[i][j]=='a'){
		e->x=j;
		e->y=i;
	}
}
void bfs(){
	node now,next;
	int time;
	queue<node>line;
	line.push(start);
	while(!line.empty()){
		now=line.front();
		line.pop();
		time=visit[now.y][now.x]+1;
		for(int i=0;i<4;i++){
			next.x=now.x+dir[i][0];
			next.y=now.y+dir[i][1];
			if(next.x>=1&&next.x<=N&&next.y>=1&&next.y<=M&&maze[next.y][next.x]!='#'){
				if(maze[next.y][next.x]=='a'){
					visit[next.y][next.x]=time+1;
					flag=1;
					ans.x=next.x;
					ans.y=next.y;
					return;
				}
				else if(maze[next.y][next.x]=='.'&&visit[next.y][next.x]==-1){
					visit[next.y][next.x]=time;
					line.push(next);
				}
				else if(maze[next.y][next.x]=='x'&&visit[next.y][next.x]==-1){
					visit[next.y][next.x]=time+1;
					line.push(next);
				}
			}
		}
	}
}
int main(){
	freopen("1242.in","r",stdin);
	while(scanf("%d%d%*c",&M,&N)!=EOF){
		memset(visit,-1,sizeof(visit));
		flag=0;
		for(int i=1;i<=M;i++)
		gets(maze[i]+1);
		Find(&start,&end);
		bfs();
		if(flag) printf("%d\n",visit[ans.y][ans.x]);
		else printf("Poor ANGEL has to stay in the prison all his life.\n");
	}
}
