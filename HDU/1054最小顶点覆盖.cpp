#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
vector<int>G[1505];
int match[1505];
bool used[1505];
bool find(int x){
	for(int i=0;i<G[x].size();++i){
		int t=G[x].at(i);
		if(!used[t]){
			used[t]=1;
			if(match[t]==-1||find(match[t])){
				match[t]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int t,n,l,m;
	while(cin>>t){
		for(int i=0;i<1505;++i) G[i].clear();
		memset(match,-1,sizeof(match));
		for(int i=0;i<t;++i){
			scanf("%d: (%d)",&n,&l);
			while(l--){
				scanf("%d",&m);
				G[n].push_back(m);
				G[m].push_back(n);
			}
		}
		int ans=0;
		for(int i=0;i<t;++i){
			memset(used,0,sizeof(used));
			if(find(i)) ans+=1;
		}
		cout<<t-ans/2<<'\n';
	}
}

