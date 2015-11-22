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
int road,city,e,mn,en[1005];
void dijkstra(int s){
	bool vis[1005]={0};
	for(int i=0;i<=mn;++i) cost[i]=map[s][i];
	cost[s]=0;
	vis[s]=1;
	for(int i=0;i<=mn;++i){
		int minc=0xfffffff,k=s,j;
		for(j=0;j<=mn;++j){
			if(!vis[j]&&cost[j]<minc){
				minc=cost[j];
				k=j;
			}
		}
		vis[k]=1;
		for(j=0;j<=mn;++j){
			if(!vis[j]&&cost[j]>cost[k]+map[k][j]){
				cost[j]=map[k][j]+cost[k];
			}
		}
	}
}
int main(){
	int a,b,c;
	while(cin>>road>>city>>e){
		mn=0;
		for(int i=0;i<1005;++i) for(int j=0;j<1005;++j) map[i][j]=0xfffffff;
		for(int i=0;i<road;++i){
			cin>>a>>b>>c;
			map[a][b]=map[b][a]=map[a][b]>c? c: map[a][b];
			if(mn<a) mn=a;
			if(mn<b) mn=b;
		}
		for(int i=0;i<city;++i){
			cin>>a;
			map[0][a]=0;
		}
		for(int i=0;i<e;++i)
			cin>>en[i];
		dijkstra(0);
		int min=0xfffffff;
		for(int i=0;i<e;++i){
			min=min>cost[en[i]]?cost[en[i]]:min;
		}
		printf("%d\n",min);
	}
}
