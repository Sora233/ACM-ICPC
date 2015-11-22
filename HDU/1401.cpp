#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
struct node{
	int x[4],y[4];
	int cost;
	bool operator==(node &a){
		for(int i=0;i<4;i++) if(this->x[i]!=a.x[i]||this->y[i]!=a.y[i]) return 0;
		return 1;
	}
}fir,sec;
const int dir[]={1,0,0,1,-1,0,0,-1};
bool xok[9][9][9][9];
bool yok[9][9][9][9];
void ins(node a){
	xok[a.x[0]][a.x[1]][a.x[2]][a.x[3]]=1;
	yok[a.y[0]][a.y[1]][a.y[2]][a.y[3]]=1;
}
bool ok(node a){
	for(int i=0;i<4;i++)
	if(a.x[i]<1||a.y[i]<1||a.x[i]>8||a.y[i]>8) return 0;
	
	for(int i=0;i<4;i++)  //判重 
	for(int j=0;j<4;j++)
	if(i==j) continue;
	else if(a.x[i]==a.x[j]&&a.y[i]==a.y[j]) return 0;
	
	if(!xok[a.x[0]][a.x[1]][a.x[2]][a.x[3]]||!yok[a.y[0]][a.y[1]][a.y[2]][a.y[3]]) return 1;
	return 0;
} 
bool move(node *a,int i,int j){
	int flag=0;
	node temp=*a;
	temp.x[i]+=dir[j];
	temp.y[i]+=dir[j+1];
	for(int l=0;l<4&&!flag;l++)
		if(l==i) continue;
		else if((*a).x[i]==temp.x[i]&&(*a).y[i]==temp.y[i]) flag=1;  //有跳板 
	if(!flag) return 0;
	(*a).x[i]+=dir[j]*2;
	(*a).y[i]+=dir[j+1]*2;
	return 1;
}
bool bfs(){
	queue<node>q;
	node now,next;
	q.push(fir);
	ins(fir);
	while(!q.empty()){
		now=q.front();
		q.pop();
		if(now.cost>8) continue;
		if(now==sec&&now.cost<=8) return 1;
		for(int j=0;j<8;j+=2) //4方向单步 
		for(int i=0;i<4;i++){
			next=now;
			next.x[i]+=dir[j];
			next.y[i]+=dir[j+1];
			if(ok(next)){
				next.cost++;
				q.push(next);
				ins(next);
			}
		}
		for(int j=0;j<8;j+=2) 
		for(int i=0;i<4;i++){ //4方向跳跃 
			next=now;
			if(!move(&next,i,j) continue;
			if(ok(next)){
				next.cost++;
				q.push(next);
				ins(next);
			}
		}
	}
	return 0;
}
int main(){
	while(cin>>fir.x[0]>>fir.y[0]){
		fir.cost=0;
		sec.cost=0;
		memset(xok,0,sizeof(xok));
		memset(yok,0,sizeof(yok));
		for(int i=1;i<4;i++)
		cin>>fir.x[i]>>fir.y[i];
		for(int i=0;i<4;i++)
		cin>>sec.x[i]>>sec.y[i];
		if(bfs()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
