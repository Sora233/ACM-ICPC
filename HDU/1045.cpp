#include<iostream>
#include<cstring>
using namespace std;
struct node{
	int x,y;
};
int size,count,Max,flag;
char map[10][10];
bool can(int y,int x){
	int flag_l=0,flag_r=0,flag_u=0,flag_d=0;
	for(int l=x-1;!flag_l;l--)
	if(map[y][l]=='X'||l==1) flag_l=1;
	else if (map[y][l]=='D') break;
	for(int r=x+1;!flag_r;r++)
	if(map[y][r]=='X'||r==size) flag_r=1;
	else if(map[y][r]=='D') break;
	for(int u=y-1;!flag_u;u--)
	if(map[u][x]=='X'||u==1) flag_u=1;
	else if(map[u][x]=='D') break;
	for(int d=y+1;!flag_d;d++)
	if(map[d][x]=='X'||d==size) flag_d=1;
	else if(map[d][x]=='D') break;
	if(flag_l&&flag_r&&flag_u&&flag_d) return 1;
	return 0;
}
node next(node now){
	node nt=now;
	if(nt.x==size) ++nt.y,nt.x=1;
	else ++nt.x;
	return nt;
}
void dfs(node now){
	if(now.y>size) flag=1;
	if(flag) return;
	if(map[now.y][now.x]=='.'&&can(now.y,now.x)){
		map[now.y][now.x]='D';  //D±íÊ¾µð±¬
		count++;
		if(count>Max) Max=count;
		dfs(next(now));
		if(flag) return;
		map[now.y][now.x]='.';  //»ØËÝ 
		count--; 
	}
	else dfs(next(now));
}
int main(){
	node start;
	start.x=start.y=1;
    while(cin>>size&&size){
    	count=0,Max=0,flag=0;
    	memset(map,0,sizeof(map));
    	for(int i=1;i<=size;i++)
    	cin>>map[i]+1;
    	for(int i=1;i<=9;i++){
    	start.x=i;
		dfs(start);
	    }
    	cout<<Max<<endl;
    }
}
