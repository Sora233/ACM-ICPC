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
const int MN=1005;
char a[MN];
int num[MN],len;
int dp[MN][30],n,m;
int min(int i,int j){
	return a[i]>a[j]?j:i;
}
void rmq_pve(){//用数组的下标而不是数组值做ST 
	for(int i=0;i<len;++i) dp[i][0]=i;
	for(int j=1;(1<<j)<len;++j)
	for(int i=0;i+(1<<j)-1<len;++i)
	dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int query(int l,int r){
	double u=log(r-l+1),d=log(2.0);
	int k=(int)(u/d);
	return min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main(){
	while(scanf("%s %d%*c",a,&m)!=EOF){
		len=strlen(a);
		rmq_pve();
		int i=0,j=0;
		int t=len-m;
		while(t){//还剩几个数字要输出
			j=query(j,len-t); //。。。绕n久绕不出来 
			num[i++]=a[j++]-'0';
			t-=1;
		}
		for(j=0;j<i;++j){
			if(num[j]) break;
		}
		if(j==i){
			printf("0");
		}
		else {
			while(j<i){
				printf("%d",num[j]);
				j+=1;
			}
		}
		printf("\n");
	}
}

