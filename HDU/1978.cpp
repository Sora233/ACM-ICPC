#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int n,m;//ÐÐ ÁÐ
int dp[105][105]; 
int map[105][105];
bool bound(int y,int x){
	return (y>0&&x>0&&x<=m&&y<=n);
}
int DP(int x,int y){
	if(dp[y][x]>=0) return dp[y][x];
	dp[y][x]=0;
	for(int j)
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp,-1,sizeof(dp));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		scanf("%d",&map[i][j]);
		printf("%d\n",DP(1,1));
	}
}

