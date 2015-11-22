#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int map[105][105];
int cost[105];
int n,m;//点 边 
void dijkstra(int s){
	bool vis[105]={0};
	for(int i=0;i<=n;++i) cost[i]=map[s][i];
	cost[s]=0;
	vis[s]=1;
	
	for(int i=1;i<=n;++i){
		int mincos=0xfffffff,k=s,j;
		for(j=1;j<=n;++j){
			if(!vis[j]&&mincos>cost[j]){
				k=j; //选取当前点最短的路 
				mincos=cost[j];
			}
		}
		vis[k]=1; //选定 mark 
		for(j=1;j<=n;++j){
			int nowcos=cost[k]+map[k][j];
			if(!vis[j]&&nowcos<cost[j]){
				cost[j]=nowcos;
			}
		}
	}
}
int main(){
	int a,b,c,s,t;
	while(cin>>n>>m&&(n||m)){
		for(int i=0;i<105;++i) for(int j=0;j<105;++j) map[i][j]=0xfffffff;
		for(int i=0;i<m;++i){
			cin>>a>>b>>c;
			map[a][b]=map[b][a]=c;
		}
		dijkstra(1);
		printf("%d\n",cost[n]);
	}
}

