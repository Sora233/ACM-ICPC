#include<cstdio>
#include<cstring>
#define MAXN 100000
int uset[MAXN];
void Makeset(int n){
	for(int i=0;i<n;i++){
		uset[i]=-1;
	}
}
int Find(int x) {
    if (uset[x]<0) return x;
    uset[x] = Find(uset[x]);
    return uset[x];
}
void Union(int m,int n){
	m=Find(m);
	n=Find(n);
	if(m==n) return;
	if(m>n){
		uset[m]+=uset[n];
		uset[n]=m;
	}
	else {
		uset[n]+=uset[m];
		uset[m]=n;
	}
}
main(){
	int t,m,n,ans,max;
	while(scanf("%d",&t)!=EOF){
		Makeset(MAXN);
		ans=1;
		max=0;
		while(t--){
			scanf("%d%d",&m,&n);
			if(m>max) max=m;
			if(n>max) max=n;
			Union(m,n);
		}
		for(int i=1;i<=max;i++)
			if(uset[i]<0&&ans<-uset[i]) ans=-uset[i];
	printf("%d\n",ans);
}
}
