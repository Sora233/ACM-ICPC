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
using namespace std;
const int MN=305;
int m,n;
int kn[305];
int dp[MN][MN][25][25];
void preST(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;++i)
	for(int j=1;j<=n;++j)
	scanf("%d",&dp[i][j][0][0]);
	for(int ii=0;ii<=kn[m];++ii)
	for(int jj=0;jj<=kn[n];++jj)
		if(jj+ii){
			for(int i=1;i+(1<<ii)-1<=m;++i)
				for(int j=1;j+(1<<jj)-1<=n;++j){
					if(ii) dp[i][j][ii][jj]=max(dp[i][j][ii-1][jj],dp[i+(1<<(ii-1))][j][ii-1][jj]);
					else dp[i][j][ii][jj]=max(dp[i][j][ii][jj-1],dp[i][j+(1<<(jj-1))][ii][jj-1]);
				}
		}
}
int query(int r1,int c1,int r2,int c2){
	int k1=kn[r2-r1+1],k2=kn[c2-c1+1];
	r2=r2-(1<<k1)+1;
	c2=c2-(1<<k2)+1;
	int m1=max(dp[r1][c1][k1][k2],dp[r1][c2][k1][k2]);
	int m2=max(dp[r2][c1][k1][k2],dp[r2][c2][k1][k2]);
	return max(m1,m2);
}	
int main(){
	kn[0]=-1;
	for(int i=1;i<305;++i)
		kn[i]=(i&(i-1))==0?kn[i-1]+1:kn[i-1];
	while(scanf("%d%d",&m,&n)!=EOF&&(m>0&&n>0)){
		preST();
		int q;
		scanf("%d",&q);
		while(q--){
			int r1,r2,c1,c2,flag=0;
			scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
			int m=query(r1,c1,r2,c2);
			if(dp[r1][c1][0][0]==m||dp[r2][c1][0][0]==m||dp[r1][c2][0][0]==m||dp[r2][c2][0][0]==m)
			flag=1;
			printf("%d %s\n",m,flag?"yes":"no");
		}
	}
}

