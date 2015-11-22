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
int seed[1005];
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
int main(){
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		memset(seed,-1,sizeof(seed));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			join(a,b);
		}
		int ans=0;
		for(int i=1;i<=n;++i) if(seed[i]<0) ans+=1;
		printf("%d\n",ans);
	}
}

