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
int seed[105];
int find(int x){
	return seed[x]<0?x:seed[x]=find(seed[x]);
}
int join(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return 0;
	if(seed[a]<seed[b]) seed[a]+=seed[b], seed[b]=a;
	else seed[b]+=seed[a],seed[a]=b;
	return 1;
}
int road,city;
struct Edg{
	int a,b,cost;
}edg[100005];
int cmp(Edg a,Edg b){
	return a.cost<b.cost;
}
int krul(){
	int ans=0;
	for(int i=0;i<road;++i){
		if(join(edg[i].a,edg[i].b))
			ans+=edg[i].cost;
	}
	return ans;
}
int main(){
	int a,b,c;
	while(scanf("%d%d",&road,&city)!=EOF&&road){
		memset(seed,-1,sizeof(seed));
		for(int i=0;i<road;++i){
			scanf("%d%d%d",&edg[i].a,&edg[i].b,&edg[i].cost);
		}
		sort(edg,edg+road,cmp);
		int ans=krul(),flag=1;
		for(int i=1;i<=city&&flag;++i){
			if(seed[i]<0) seed[0]+=1;
			if(seed[0]==1) flag=0;
		}
		if(flag) printf("%d\n",ans);
		else printf("?\n");
	}
}

