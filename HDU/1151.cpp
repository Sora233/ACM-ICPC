#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int node,edg;
vector<int>G[130];
bool used[130];
int match[130];
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
	int t,a,b;
	cin>>t;
	while(t--){
		memset(match,-1,sizeof(match));
		for(int i=0;i<130;++i) G[i].clear();
		cin>>node>>edg;
		for(int i=0;i<edg;++i){
			cin>>a>>b;
			G[a].push_back(b);
		}
		int ans=0;
		for(int i=1;i<=node;++i){
			memset(used,0,sizeof(used));
			if(find(i)) ans+=1;
		}
		cout<<node-ans<<'\n';
	}
}

