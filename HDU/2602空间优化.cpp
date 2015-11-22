#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N,V;
		scanf("%d%d",&N,&V);
		int bone[1005]={0},val[1005]={0},dp[1005]={0};
		for(int i=1;i<=N;i++)
		scanf("%d",&val[i]);
		for(int i=1;i<=N;i++)
		scanf("%d",&bone[i]);
		for(int i=1;i<=N;i++)
		for(int j=V;j>=bone[i];j--)
		if(dp[j]<dp[j-bone[i]]+val[i]) dp[j]=dp[j-bone[i]]+val[i];
		printf("%d\n",dp[V]);
	}
}
