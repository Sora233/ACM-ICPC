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
int city,road,nowc;
struct node{
	int to,val;
}p;
vector<node>G[3005];
int dis[3005];
int change(int from,int to,int val){
	for(int i=0;i<G[from].size();++i){
		if(G[from][i].to==to){
			nowc=G[from][i].val;
			G[from][i].val=val;
			return i;
		}
	}
}
int prim(){
	int res=0;
	bool used[3005]={0};
	for(int i=0;i<city;++i) dis[i]=0xfffffff;
	for(int i=0;i<G[0].size();++i) dis[G[0][i].to]=G[0][i].val;
	dis[0]=0;
	used[0]=1;
	for(int l=0;l<city-1;++l){
		int minx=0xfffffff,vert;
		for(int i=0;i<city;++i)
			if(!used[i]&&minx>dis[i]) minx=dis[i],vert=i;
		used[vert]=1;
		res+=minx;
		for(int i=0;i<G[vert].size();++i){
			if(!used[i]&&dis[G[vert][i].to]>G[vert][i].val) dis[G[vert][i].to]=G[vert][i].val;
		}
	}
	return res;
}
int main(){
	int a,b,c,ch,t;
	while(scanf("%d%d",&city,&road)!=EOF&&(city||road)){
		int ans=0;
		for(int i=0;i<city;++i) G[i].clear();
		for(int i=0;i<road;++i){
			scanf("%d%d%d",&a,&b,&p.val);
			p.to=b;
			G[a].push_back(p);
			p.to=a;
			G[b].push_back(p);
		}
		scanf("%d",&ch);
		for(int i=0;i<ch;++i){
			scanf("%d%d%d",&a,&b,&c);
			int la=change(a,b,c);
			int lb=change(b,a,c);
			ans+=prim();
			G[a][la].val=nowc;
			G[b][lb].val=nowc;
		}
		printf("%.4f\n",ans*1.0/ch);
	}
}

