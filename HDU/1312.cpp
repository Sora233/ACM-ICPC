#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
int W,H; //行 列 
char maze[21][21];
bool visit[21][21];
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}}; //右 上 左 下 
struct node{
	int x,y;
};
node start;
void Find_s(){
	for(int i=1;i<=H;i++)
	for(int j=1;j<=W;j++)
	    if(maze[i][j]=='@'){
	    	start.y=i;
	    	start.x=j;
	    	return;
	    }
}
int Sum(){
	int sum=0;
	for(int i=1;i<=H;i++)
	for(int j=1;j<=W;j++)
	if(visit[i][j]) sum++;
	return sum;
}
void bfs(){
	node now,next;
	queue<node>line;
	line.push(start);
	while(!line.empty()){
		now=line.front();
		line.pop();
		visit[now.y][now.x]=1;
		for(int i=0;i<4;i++){
			next.x=now.x+dir[i][0];
			next.y=now.y+dir[i][1];
			if(next.x>=1&&next.x<=W&&next.y>=1&&next.y<=H&&maze[next.y][next.x]!='#'&&!visit[next.y][next.x]){
				line.push(next);
				visit[next.y][next.x]=1;
			}
		}
	}
}
int main(){
	//freopen("1312.in","r",stdin);
	while(scanf("%d%d%*c",&W,&H)!=EOF){
		if(!W&&!H) break;
		memset(visit,0,sizeof(visit));
		for(int i=1;i<=H;i++)
		gets(maze[i]+1);
		Find_s();
		bfs();
		printf("%d\n",Sum());
	}
}
