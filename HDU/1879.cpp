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
struct node{
	int a,b,cost,ok;
}edg[110005];
int seed[105];
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
int city;
int cmp(node a,node b){
	return a.cost<b.cost;
}
int krul(){
	int ans=0;
	for(int i=0;i<city*(city-1)/2;++i){
		if(join(edg[i].a,edg[i].b)) ans+=edg[i].cost;
	}
	return ans;
}
int main(){
	while(scanf("%d",&city)!=EOF&&city){
		memset(seed,-1,sizeof(seed));
		for(int i=0;i<city*(city-1)/2;++i){
			scanf("%d%d%d%d",&edg[i].a,&edg[i].b,&edg[i].cost,&edg[i].ok);
			if(edg[i].ok) join(edg[i].a,edg[i].b);
		}
		sort(edg,edg+city*(city-1)/2,cmp);
		printf("%d\n",krul());
	}
}

