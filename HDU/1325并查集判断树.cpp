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
int vis[100005];
int main(){
	int a,b,ca=1,ma,flag;
	while(scanf("%d",&a)!=EOF&&a>=0){
		flag=1;
		memset(vis,-1,sizeof(vis));
		scanf("%d",&b);
		if(b<0) break;
		if(a==0&&b==0){
			printf("Case %d is a tree.\n",ca++);
			continue;
		}
		ma=max(ma,max(a,b));
		vis[b]+=1;
		while(scanf("%d%d",&a,&b)!=EOF&&a&&b) {
			vis[b]+=1;
			ma=max(ma,max(a,b));
		}
		int ans=0;
		for(int i=1;i<=ma&&flag;++i){
			if(vis[i]==-1) continue;
			if(vis==0) ans+=1;
			if(vis[i]>0||ans==2) flag=0;
		}
		if(flag) printf("Case %d is a tree.\n",ca++);
		else printf("Case %d is not a tree.\n",ca++);
	}
}

