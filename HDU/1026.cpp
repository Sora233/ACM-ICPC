#include<stdio.h>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;
char maze[101][101];
int H,W,min_cost;
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}}; //右 下 左 上 
bool visit[101][101];
struct po{
	int x,y;
	int cost;
	bool operator< (const po &a) const{ //时间小先出队 
	return cost>a.cost;
	}
};
struct rep{
	int x,y;
	rep operator=(const po &a){
		this->x=a.x;
		this->y=a.y;
		return *this;
	}
}reply[101][101];
bool can(po a){
	if(a.x>=1&&a.x<=W&&a.y>=1&&a.y<=H&&!visit[a.y][a.x]&&maze[a.y][a.x]!='X') return 1;
	return 0;
}
bool bfs(){
	po start,now,next;
	priority_queue<po>q;
	start.x=start.y=1;
	start.cost=0;
	q.push(start);
	while(!q.empty()){
		now=q.top();
		q.pop();
		if(now.x==W&&now.y==H){
			min_cost=now.cost;
			return 1;
		}
		for(int i=0;i<4;i++){
			next.x=now.x+dir[i][0];
			next.y=now.y+dir[i][1];
			next.cost=now.cost+1;
			if(can(next)){
				if(maze[next.y][next.x]=='.'){
			    q.push(next);
			    }
				else {
					next.cost+=maze[next.y][next.x]-'0';
					q.push(next);
				}
		    visit[next.y][next.x]=1;
		    reply[next.y][next.x]=now;
			}
		}
	}
	return 0;
}
void prin(){
	stack<rep>s;
	rep end,turn,t;
	end.x=W,end.y=H;
	s.push(end);
	t=end;
	while(1){
		if(t.y==1&&t.x==1) break;
		turn=reply[t.y][t.x];
		s.push(turn);
		t=turn;
	}
	int count=1;
	turn=s.top();
	s.pop();
	while(!s.empty()){
		t=s.top();
		s.pop();
		printf("%ds:(%d,%d)->(%d,%d)\n",count++,turn.y-1,turn.x-1,t.y-1,t.x-1);
		if(maze[t.y][t.x]>='1'&&maze[t.y][t.x]<='9'){
			int c=maze[t.y][t.x]-'0';
			while(c--){
				printf("%ds:FIGHT AT (%d,%d)\n",count++,t.y-1,t.x-1);
			}
		}
		turn=t;
	}
	printf("FINISH\n");
}
int main(){
	//freopen("1026.in","r",stdin);
	while(scanf("%d %d%*c",&H,&W)!=EOF){
		memset(visit,0,sizeof(visit));
		memset(reply,0,sizeof(reply));
		min_cost=0;
		for(int i=1;i<=H;i++)
		gets(maze[i]+1);
		visit[1][1]=1;
		if(!bfs()) printf("God please help our poor hero.\nFINISH\n");
		else {
			printf("It takes %d seconds to reach the target position, let me show you the way.\n",min_cost);
			prin();
		}
	}
}
