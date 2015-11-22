#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int map[1005][1005];
int cost[1005];
int n,m,s,stan;
void ins(){
	for(int i=0;i<1005;++i)for(int j=0;j<1005;++j) map[i][j]=0xfffffff;
}
void dijkstra(int s){
	bool vis[1005]={0};
	for(int i=0;i<=n;++i) cost[i]=map[s][i];
	vis[s]=1,cost[s]=0;
	for(int i=0;i<=n;++i){
		int minc=0xfffffff,choose=s,j;
		for(j=0;j<=n;++j){
			if(!vis[j]&&minc>cost[j])
				choose=j,minc=cost[j];
		}
		vis[choose]=1;
		for(j=0;j<=n;++j){
			int nowc=cost[choose]+map[choose][j];
			if(!vis[j]&&nowc<cost[j])
				cost[j]=nowc;
		}
	}
}
int main(){
	int a,b,c;
	while(scanf("%d%d%D",&n,&m,&s)!=EOF){
		ins();
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&a,&b,&c);
			map[a][b]=map[a][b]>=c?c:map[a][b];
		}
		scanf("%d",&stan);
		for(int i=0;i<stan;++i){
			scanf("%d",&a);
			map[0][a]=0;
		}
		dijkstra(0);
		printf("%d\n",cost[s]==0xfffffff?-1:cost[s]);
	}
}

