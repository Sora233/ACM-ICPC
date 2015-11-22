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
int seed[505];
int find(int x){
	return seed[x]<0?x:seed[x]=find(seed[x]);
}
int join(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return 0;
	if(seed[a]>seed[b]) seed[b]+=seed[a],seed[a]=b;
	else seed[a]+=seed[b],seed[b]=a;
	return 1;
}
struct Edg{
	int a,b,cost;
}edg[25005];
int city,road,ok;
int cmp(Edg a,Edg b){
	return a.cost<b.cost;
}
int krul(){
	int res=0;
	for(int i=0;i<road;++i)
		if(join(edg[i].a,edg[i].b)) res+=edg[i].cost;
	return res;
}
int main(){
	int t,a,b,c;
	scanf("%d",&t);
	while(t--){
		memset(seed,-1,sizeof(seed));
		scanf("%d%d%d",&city,&road,&ok);
		for(int i=0;i<road;++i)
			scanf("%d%d%d",&edg[i].a,&edg[i].b,&edg[i].cost);
		for(int i=0;i<ok;++i){
			scanf("%d%d",&a,&b);
			for(int j=1;j<a;++j){
				scanf("%d",&c);
				join(b,c);
			}
		}
		sort(edg,edg+road,cmp);
		int ans=krul(),flag=1;
		for(int i=1;i<=city&&flag;++i){
			if(seed[i]<0) seed[0]+=1;
			if(seed[0]==1) flag=0;
		}
		printf("%d\n",flag?ans:-1);
	}
}

