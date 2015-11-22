#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
//////////////
int seed[30];
int find(int x){
	return seed[x]<0? x : seed[x]=find(seed[x]);
}
int join(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return 0;
	if(seed[a]>=seed[b]) seed[b]+=seed[a],seed[a]=b;
	else seed[a]+=seed[b],seed[b]=a;
	return 1;
}
int in[30],out[30];//记录出度入度 
int abs(int a){
	return a>=0?a:-a;
}
int main(){
	int t,a,b,flag,n,k;
	char s[1005];
	scanf("%d%*c",&t);
	while(t--){
		flag=1,k=0;
		scanf("%d%*c",&n);
		for(int i=0;i<30;++i) in[i]=out[i]=0;
		memset(seed,-1,sizeof(seed));
		while(n--){
			gets(s);
			a=s[0]-'a'+1;
			b=s[strlen(s)-1]-'a'+1;
			in[a]+=1,out[b]+=1;
			join(a,b);
		}
		for(int i=1;i<30&&flag;++i){
			if(seed[i]<0&&(in[i]&&out[i])) seed[0]+=1;
			if(seed[0]==1) flag=0;
		}
		for(int i=1;i<30&&flag;++i){
			if(abs(in[i]-out[i])==1) k+=1;
			else if(in[i]!=out[i]) flag=0;
			if(k>2) flag=0;
		}
		printf("%s\n",flag?"Ordering is possible.":"The door cannot be opened.");
	}
}

