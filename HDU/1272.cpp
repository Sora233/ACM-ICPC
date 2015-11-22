#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int seed[100005];
bool room[100005];
int find(int x){
	return seed[x]<0?x : seed[x]=find(seed[x]);
}
bool join(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return 0;
	if(seed[a]>seed[b])seed[b]+=seed[a],seed[a]=b;
	else seed[a]+=seed[b],seed[b]=a;
	return 1;
}
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int Max,a,b,flag,ca=0;
	while(cin>>a>>b){
		if(!a&&!b) {
			printf("Yes\n");
			continue;
		}
		memset(room,0,sizeof(room));
		room[a]=1,room[b]=1;
		memset(seed,-1,sizeof(seed));
		Max=0,flag=1;
		if(a==-1&&b==-1) break;
		join(a,b);
		Max=max(Max,max(a,b));
		while(cin>>a>>b&&a&&b){
			room[a]=1,room[b]=1;
			if(!join(a,b)) flag=0;
			Max=max(Max,max(a,b));
		}
		for(int i=1;flag&&i<=Max;++i){
			if(!room[i]) continue;
			if(seed[i]<0) seed[0]+=1;
			if(seed[0]==1) flag=0;
		}
		printf("%s\n",flag?"Yes":"No");
	}
}

