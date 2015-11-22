#include<iostream>
#include<cstring>
using namespace std;
int H,W,count;
char map[105][105];
bool ved[105][105];
int dir[8][2]={{-1,-1},{0,-1},{-1,0},{0,1},{1,0},{-1,1},{1,-1},{1,1}};
bool Can(int y,int x){
	if(y<1||y>H||x<1||x>W) return 0;
	if(ved[y][x]||map[y][x]!='@') return 0;
	return 1;
}
void dfs(int y,int x){
	int nx=x,ny=y;
	for(int i=0;i<8;i++)
	{
		nx=x+dir[i][0];
		ny=y+dir[i][1];
		if(Can(ny,nx)){
			ved[ny][nx]=1;
			dfs(ny,nx);
		}
	}
}
int main(){
	while(cin>>H>>W&&(H||W)){
		memset(map,0,sizeof(map));
		memset(ved,0,sizeof(ved));
		int count=0;
		for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
		cin>>map[i][j];
		for(int y=1;y<=H;y++)
		for(int x=1;x<=W;x++)
		if(map[y][x]=='@'&&!ved[y][x]){
			ved[y][x]=1;
		    dfs(y,x);
		    count++;
	    }
	    cout<<count<<endl;
	}
}
