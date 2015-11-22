#include<iostream>
#include<algorithm>
#include<cstring>
const int INF=2147483647;
using namespace std;
int dp[2005][2005];
int main(){
	int n,k;
	while(cin>>n>>k){
		int a[2005]={0};
		for(int i=1;i<=n;i++)
		cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)
		if(j)dp[i][j]=INF;
		else dp[i][j]=0;
		for(int i=2;i<=n;i++)
		for(int j=1;2*j<=i;j++)
		dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]));
		printf("%d\n",dp[n][k]);
	}
}
