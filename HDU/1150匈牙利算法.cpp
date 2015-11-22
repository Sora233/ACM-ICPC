#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int n,m,k;
vector<int>G[105];
int match[105];
bool used[105];
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
	int a,b,t;
	while(cin>>n&&n){
		cin>>m>>k;
		for(int i=0;i<105;++i) G[i].clear();
		memset(match,-1,sizeof(match));
		while(k--){
			cin>>t>>a>>b;
			if(!a||!b) continue;
			G[a].push_back(b);
		}
		int ans=0;
		for(int i=1;i<n;++i){
			memset(used,0,sizeof(used));
			if(find(i)) ans+=1;
		}
		cout<<ans<<'\n';
	}
}

