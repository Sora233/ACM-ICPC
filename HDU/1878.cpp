#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int seed[1005],flag;
int find(int x){
	return seed[x]<0? x:seed[x]=find(seed[x]);
}
void join(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return;
	if(seed[a]>seed[b]) seed[b]+=seed[a],seed[a]=b;
	else seed[a]+=seed[b],seed[b]=a;
}
int degree[1005];
int n,m;
int main(){
	int a,b;
	while(scanf("%d",&n)!=EOF&&n){
		scanf("%d",&m);
		flag=1;
		memset(seed,-1,sizeof(seed));
		memset(degree,0,sizeof(degree));
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			join(a,b);
			degree[a]+=1,degree[b]+=1;
		}
		for(int i=1;i<=n&&flag;++i){
			if(seed[i]<0) seed[0]+=1;
			if(seed[0]==2||degree[i]&1) flag=0;
		}
		printf("%d\n",flag);
	}
}

