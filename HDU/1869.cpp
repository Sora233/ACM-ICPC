#include<stdio.h>
#include<string.h>
int seed[150];
int find(int x){
	return seed[x]<0 ? x : seed[x]=find(seed[x]);
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
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(seed,-1,sizeof(seed));
		
	}
}

