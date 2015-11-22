#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int a,b;
	int cost;
}edg[10005];
//////////////////²¢²é¼¯
int seed[1005];
void ins(){
	memset(seed,-1,sizeof(seed));
}
int find(int x){
	return seed[x]<0?x : seed[x]=find(seed[x]);
}
bool join(node p){
	int a=p.a,b=p.b;
	a=find(a),b=find(b);
	if(a==b) return 0;
	if(seed[a]>seed[b]) seed[b]+=seed[a],seed[a]=b;
	else seed[a]+=seed[b],seed[b]=a;
	return 1;
}
//////////////////
int nodenum,edgnum;
bool cmp(node a,node b){
	return a.cost<b.cost;
}
void krul(){
	ins();
	int ans=0,flag=0;
	for(int i=0;i<edgnum;++i)
		if(join(edg[i]))  ans+=edg[i].cost;
	printf("%d\n",ans);
}
int main(){
	int a,b,c;
	while(cin>>nodenum>>edgnum){
		memset(edg,0,sizeof(edg));
		for(int i=0;i<edgnum;++i)
		scanf("%d%d%d",&edg[i].a,&edg[i].b,&edg[i].cost);
		sort(edg,edg+edgnum,cmp);
		krul();
		printf("\n");
	}
}

