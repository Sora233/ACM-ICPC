#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
struct graph{
	int vernum,edgnum;
	vector<int>edg[10005];
}G;
int T;
void ints(){
	int i,a,b,val;
	scanf("%d%d%d",&G.vernum,&G.edgnum,&T);
	for(i=1;i<=G.vernum;++i) G.edg[i].clear();
	for(i=0;i<G.edgnum;++i){
		scanf("%d%d%d")
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ints();
	}
}

