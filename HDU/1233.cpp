#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int inf=0xfffffff;
int uset[105],n; //¶¥µãÊý ;
struct edg{
    int a,b,dis;	
}e[5055];
void ints(){
	for(int i=0;i<105;++i)
	uset[i]=-1;
}
int find(int x){
	if(uset[x]<0) return x;
	uset[x]=find(uset[x]);
	return uset[x];
}
void comb(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return;
	if(uset[a]<=uset[b]){
	    uset[a]+=uset[b];
		uset[b]=a;		
	}
	else {
		uset[b]+=uset[a];
		uset[a]=b;
	}
}
bool cmp(edg a,edg b){
	return b.dis>a.dis;
}
void Kruskal(){
	int sum=0,edgnum=0;
	for(int i=0;edgnum<n-1;++i){
		if(find(e[i].a)==find(e[i].b)) continue;
		comb(e[i].a,e[i].b);
        ++edgnum;
        sum+=e[i].dis;
	}
	printf("%d\n",sum);
}
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		memset(e,0,sizeof(e));
		int a,b,dis,edgnum;
		ints();
		edgnum=n*(n-1)/2;
		for(int i=0;i<edgnum;++i)
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].dis);
		sort(e,e+edgnum,cmp);
		Kruskal();
	}
}
