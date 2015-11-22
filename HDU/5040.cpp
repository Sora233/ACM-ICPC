#include<stdio.h>
#include<math.h>
#include<string.h>
#include<queue>
using namespace std;
char map[505][505];
bool movemap[505][505][4];
bool vis[505][505][4];//0 1 2 3 
bool previs[505][505];
int dir[4][2]={{0,-1},{1,0},{0,1},{-1,0}}; //上 右 下 左 
int N; //N*N
struct node{
	int x,y,t;
	node(){
		x=0,y=0,t=0;
	}
	bool operator== (node p){
		if(x==p.x&&y==p.y) return 1;
		return 0;
	}
	bool operator< (node p)const {
		return t>p.t;
	}
}sta,en;
bool posok(int i,int j){
	if(i>0&&j>0&&i<=N&&j<=N&&map[i][j]!='#') return 1;
	return 0;
}
void mark_movemap(int i,int j,char d){
	movemap[i][j][0]=movemap[i][j][1]=movemap[i][j][2]=movemap[i][j][3]=0;
	for(int cou=0;cou<4;++cou){
		int way=d-'0';
		if(posok(i+dir[way][1],j+dir[way][0])) movemap[i+dir[way][1]][j+dir[way][0]][cou]=0;
		d+=1;
		if(d=='4') d='0';
	}
}
void mark_path(node st){
	vis[st.y][st.x][st.t%4]=1;
}
bool qur_vis(node p){//已走过返回1 
	return vis[p.y][p.x][p.t%4];
}
bool prebfs(){
	memset(previs,0,sizeof(previs));
	node now,next;
	queue<node>line;
	line.push(sta);
	previs[sta.y][sta.x]=1;
	while(!line.empty()){
		now=line.front();
		line.pop();
		for(int i=0;i<4;++i){
			next.x=now.x+dir[i][0],next.y=now.y+dir[i][1];
			if(!posok(next.y,next.x)||previs[next.y][next.x]) continue;
			line.push(next);
			previs[next.y][next.x]=1;
			if(next==en) return 1;
		}
	}
	return 0;
}
int bfs(){
	int i,j;
	node now,next;
	priority_queue<node>line;
	line.push(sta);
	mark_path(sta);
	while(!line.empty()){
		now=line.top();
		line.pop();
		for(i=0;i<4;++i){
			next.y=now.y+dir[i][1],next.x=now.x+dir[i][0];
			next.t=now.t+1;
			if(!posok(next.y,next.x)||qur_vis(next)) continue; //越界撞墙已走过 
			if(movemap[next.y][next.x][(next.t-1)%4]&&movemap[next.y-dir[i][1]][next.x-dir[i][0]][(next.t-1)%4]){
				line.push(next);
				mark_path(next);
				if(next==en) return next.t;
			}
			else {//原地等待 
				for(j=0;j<3;++j){
					next.t+=1;
					if(movemap[next.y][next.x][(next.t-1)%4]&&movemap[next.y-dir[i][1]][next.x-dir[i][0]][(next.t-1)%4]){
						line.push(next);
						mark_path(next);
						if(next==en) return next.t;
						break;
					}
				}
				if(j==4){
					next.t=now.t+3;
					line.push(next);
					mark_path(next);
					if(next==en) return next.t;
				}
			}
		}
	}
	return -1;
}
int main(){
	int ca,T,i,j;
	scanf("%d%*c",&T);
	for(ca=1;ca<=T;++ca){
		scanf("%d%*c",&N);
		for(i=0;i<505;++i) for(int j=0;j<505;++j) for(int l=0;l<4;++l) movemap[i][j][l]=1;
		memset(vis,0,sizeof(vis));
		for(i=1;i<=N;++i){
			gets(map[i]+1);
			for(j=1;j<=N;++j){
				if(map[i][j]=='M'||map[i][j]=='T') {
					if(map[i][j]=='M')sta.x=j,sta.y=i;
					else if (map[i][j]=='T') en.x=j,en.y=i;
				}
				else if(map[i][j]=='#') movemap[i][j][0]=movemap[i][j][1]=movemap[i][j][2]=movemap[i][j][3]=0;
				else if(map[i][j]!='.') {
					switch(map[i][j]){
						case 'N':map[i][j]='0';break;
						case 'E':map[i][j]='1';break;
						case 'S':map[i][j]='2';break;
						case 'W':map[i][j]='3';break;
					}
					mark_movemap(i,j,map[i][j]);
				}
			}
		}
		if(!prebfs()){
			printf("Case #%d: -1\n",ca);
			continue;
		}
		printf("Case #%d: %d\n",ca,bfs());
	}
}

