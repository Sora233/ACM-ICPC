#include<iostream>
#define ll long long int
using namespace std;
int gel(ll n){
	int ans=0;
	while(n) n/=10,ans++;
	return ans;
}
int main(){
	ll n;
	while(cin>>n){
		int len=gel(n);
		ll dp[20][10][3]={0};
		dp[0][0][0]=1;
		for(int i=1;i<=20;i++) //总位数
		for(int j=1;j<=9;j++)  //最高位
		{
			if(j!=4) dp[i][j][0]=dp[i-1][j][0]*10-dp[i-1][9][1];        //0==最多i位最高位为j的不含49的个数 
			else dp[i][j][0]=dp[i-1][j][0]*10;                       //1==恰i位最高位为j的不含49的个数 
			if(j!=9) dp[i][j][1]=dp[i-1][j][1]*10;
   		}
	}
}
