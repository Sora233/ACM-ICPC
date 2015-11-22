#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
int end[4];
struct node{
	int n[4];
	int cost;
}start;
bool ok[10][10][10][10];
void getss(int a[]){
	string s;
	cin>>s;
	for(int i=0;i<4;i++){
	a[i]=s[i]-'0';
    }
}
void exc(int *a,int *b){
	int c;
	c=*a,*a=*b,*b=c;
}
void ins(node a){
	ok[a.n[0]][a.n[1]][a.n[2]][a.n[3]]=1;
	return;
}
bool complet(node a){
	for(int i=0;i<4;i++)
	if(a.n[i]!=end[i]) return 0;
	return 1;
}
bool oks(node a){
	return ok[a.n[0]][a.n[1]][a.n[2]][a.n[3]];
}
int bfs(){
	queue<node>q;
	node temp,next;
	q.push(start);
	ins(start);
	while(!q.empty()){
	temp=q.front();
	q.pop();
	if(complet(temp)) 
	return temp.cost;
	for(int i=0;i<4;i++){
		next=temp;
		next.n[i]+=1;
		if(next.n[i]>9) next.n[i]=1;
		if(!oks(next)){
		next.cost++;
		q.push(next);
		ins(next);
	    }
	}
	for(int i=0;i<4;i++){
		next=temp;
		next.n[i]-=1;
		if(next.n[i]<1) next.n[i]=9;
		if(!oks(next)){
			next.cost++;
			q.push(next);
			ins(next);
		}
	}
	for(int i=0;i<3;i++){
		next=temp;
		exc(&next.n[i],&next.n[i+1]);
		if(!oks(next)){
			next.cost++;
			q.push(next);
			ins(next);
		}
	}
	}
	return -1;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		memset(ok,0,sizeof(ok));
		start.cost=0;
		getss(start.n);
		getss(end);
		int min=bfs();
		cout<<min<<endl;
	}
}
