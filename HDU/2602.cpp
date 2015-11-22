#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1005][1005]={0};
int main(){
	int T;
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		int N,V,item[1005]={0},val[1005]={0};
		cin>>N>>V;
		for(int i=1;i<=N;i++)
		cin>>val[i];
		for(int i=1;i<=N;i++)
		cin>>item[i];
		for(int i=1;i<=N;i++)
		for(int j=0;j<=V;j++)
		if(j>=item[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-item[i]]+val[i]);
		else dp[i][j]=dp[i-1][j];
		cout<<dp[N][V]<<endl;
	}
}
