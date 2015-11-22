#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int k,gnum,bnum;
vector<int>G[505];
int match[505];
int used[505];
bool find(int x){
	for(int i=0;i<G[x].size();++i){
		int n=G[x][i];
		if(!used[n]){
			used[n]=1;
			if(match[n]==-1||find(match[n])){
				match[n]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int a,b;
	while(cin>>k&&k){
		for(int i=0;i<505;++i) G[i].clear();
		cin>>gnum>>bnum;
		for(int i=0;i<k;++i){
			cin>>a>>b;
			G[a].push_back(b);
		}
		int ans=0;
		memset(match,-1,sizeof(match));
		for(int i=1;i<=gnum;++i){
			memset(used,0,sizeof(used));
			if(find(i)) ans+=1;
		}
		cout<<ans<<endl;
	}
}

