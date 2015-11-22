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
int seed[205];
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
int city,road;
struct Edg{
	int a,b,speed;
}edg[1005];
int cmp(Edg a,Edg b){
	if(a.speed!=b.speed) return a.speed<b.speed;
	if(a.a!=b.a) return a.a<b.a;
	return a.b<b.b;
}
int ok(int a,int b){
	return find(a)==find(b);
}
int solve(int s,int e){
	int res=0xfffffff;
	for(int i=0;i<road;++i){
		memset(seed,-1,sizeof(seed));
		for(int j=i;j<road;++j){
			join(edg[j].a,edg[j].b);
			if(ok(s,e)) {
				res=min(res,edg[j].speed-edg[i].speed);
				break;
			}
		}
	}
	return res;
}
int main(){
	while(scanf("%d%d",&city,&road)!=EOF){
		for(int i=0;i<road;++i)
			scanf("%d%d%d",&edg[i].a,&edg[i].b,&edg[i].speed);
		sort(edg,edg+road,cmp);
		int q,s,e;
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&s,&e);
			int ans=solve(s,e);
			printf("%d\n",ans==0xfffffff?-1:ans);
		}
	}
}

