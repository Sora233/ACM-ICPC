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
int seed[30];
int find(int x){
	return seed[x]<0?x:seed[x]=find(seed[x]);
}
int join(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return 0;
	if(seed[a]<seed[b]) seed[a]+=seed[b],seed[b]=a;
	else seed[b]+=seed[a],seed[a]=b;
	return 1;
}
struct Edg{
	int a,b,cost;
}edg[100];
int cmp(Edg a,Edg b){
	return a.cost<b.cost;
}
int city,road;
int krul(){
	int res=0;
	for(int i=0;i<road;++i)
		if(join(edg[i].a,edg[i].b)) res+=edg[i].cost;
	return res;
}
int main(){
	char s;
	int n,c;
	while(scanf("%d%*c",&city)!=EOF&&city){
		road=0;
		memset(seed,-1,sizeof(seed));
		for(int i=1;i<city;++i){
			scanf("%c %d%*c",&s,&n);
			for(int j=0;j<n;++j){
				scanf("%c %d%*c",&s,&c);
				edg[road].a=i,edg[road].b=s-'A'+1,edg[road++].cost=c;
			}
		}
		sort(edg,edg+road,cmp);
		printf("%d\n",krul());
	}
}

