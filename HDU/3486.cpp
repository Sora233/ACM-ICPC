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
using namespace std;
const int MN=200005;
int n,k;
int dp[MN][30];
bool preST(){
	int res=0;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;++i) {
		scanf("%d",&dp[i][0]);
		res+=dp[i][0];
	}
	if(res<=k) {
		printf("-1\n");
		return 0;
	}
	for(int j=1;(1<<j)<n;++j)
		for(int i=0;i+(1<<j)-1<n;++i)
			dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
	return 1;
}
int query(int l,int r){
	int k=(int)log(r-l+1.0)/log(2.0);
	return max(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main(){
	int seg,m,ans,i,c;
	while(scanf("%d%d",&n,&k)!=EOF&&(n>0||k>0)){
		if(!preST()) continue;
		int flag=0;
		for(ans=n;ans>0;--ans){
			seg=n/ans,m=0;
			for(i=0,c=0;c<seg&&!flag;++c,i+=ans){
				m+=query(i,i+ans-1);
				printf("seg==%d,ans==%d,m==%d\n",seg,ans,m);
				if(m>k) flag=1;
			}
			if(flag) break;
		}
		printf("%d\n",c);
	}
}
