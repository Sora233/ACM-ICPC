#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int inf=0xfffffff;
struct road{
	int scity,ecity,speed;
}edg[1005];
bool cmp(road a,road b){
	return b.speed>a.speed;
}
int seed[1005],n,m,t;
int find(int x){
	return seed[x]<0?x:seed[x]=find(seed[x]);
}
int same(int a,int b){
	return find(a)==find(b);
}
int join(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return 0;
	if(seed[a]>seed[b]){
		seed[b]+=seed[a];
		seed[a]=b;
	}
	else {
		seed[a]+=seed[b];
		seed[b]=a;
	}
	return 1;
}
int solve(int st,int end){
	int ans=inf;
	for(int i=0;i<m;++i){
		int j;
		memset(seed,-1,sizeof(seed));//初始化并查集 
		for(j=i;j<m;++j){
			join(edg[j].scity,edg[j].ecity);
			if(same(st,end)){
				if(ans>edg[j].speed-edg[i].speed) ans=edg[j].speed-edg[i].speed;
				break;
			}
		}
	}
	return ans;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(edg,0,sizeof(edg));
		for(int i=0;i<m;++i) 
		scanf("%d%d%d",&edg[i].scity,&edg[i].ecity,&edg[i].speed);
		sort(edg,edg+m,cmp);
		scanf("%d",&t);
		while(t--){
			int st,end,ans;
			scanf("%d%d",&st,&end);
			ans=solve(st,end);
			printf("%d\n",ans==inf?-1:ans);
		}
	}
}

