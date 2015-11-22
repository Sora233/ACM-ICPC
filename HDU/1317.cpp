#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<string>
#define pb push_back
#define pii pair<int,int>
using namespace std;
vector<int>G[105];//first目标房 second能量 
int city,flag;
int vis[105],eng[105],c[105],er[105];
void spfa(int s){
	queue<int>line;
	eng[s]=100;
	line.push(s);
	vis[s]=1;
	while(!line.empty()){
		int now=line.front();line.pop();
		vis[now]=0;
		if(c[now]>city+1) continue;
		c[now]+=1;
		if(c[now]==city+1) eng[now]=1000000;
		for(int i=0;i<G[now].size();++i){
			int v=G[now][i],w=er[G[now][i]];
			if(w+eng[now]>eng[v]){
				eng[v]=eng[now]+w;
				if(!vis[v]){
					vis[v]=1;
					c[v]+=1;
					line.push(v);
				}	
				if(v==city) return;
			}
		}
	}
	flag=0;
	return;
}
int main(){
	int a,b,e;
	while(scanf("%d",&city)!=EOF&&(city!=-1)){
		flag=1;
		for(int i=0;i<=city;++i) {
			G[i].clear();
			vis[i]=0,eng[i]=0,c[i]=0;
		}
		for(int i=1;i<=city;++i){
			scanf("%d %d",&er[i],&b);
			for(int j=0;j<b;++j){
				scanf("%d",&e);
				G[i].pb(e);
			}
		}
		if(flag&&(city!=1&&city!=0)) spfa(1); 
		printf("%s\n",flag?"winnable":"hopeless");
	}
}

