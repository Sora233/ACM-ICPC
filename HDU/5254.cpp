#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
#include<ctime>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
bool map[505][505];
pii q[500000];
int cnt=0;
int n,m,g;
bool check(int i,int j){
	int co=0;
	if(map[i][j]) return 0;
	if(map[i-1][j]&&(map[i][j-1]||map[i][j+1])) return 1;
	if(map[i][j-1]&&(map[i+1][j]||map[i-1][j])) return 1;
	if(map[i+1][j]&&(map[i][j-1]||map[i][j+1])) return 1;
	if(map[i][j+1]&&(map[i+1][j]||map[i-1][j])) return 1;
	return 0;
}
bool no(){
	int flag=0,co;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	if(check(i,j)) {
		q[cnt++]=make_pair(i,j);
		flag=1;
	}
	return flag;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		memset(map,0,sizeof(map));
		memset(q,0,sizeof(q));
		int a,b;
		scanf("%d%d%d",&n,&m,&g); //nÐÐmÁÐ 
		for(int i=0;i<g;++i){
			scanf("%d%d",&a,&b);
			map[a][b]=1;
		}
		cnt=0;
		while(no()){
			while(cnt){
				int x=q[cnt-1].first,y=q[cnt-1].second;cnt-=1;
				map[x][y]=1;
				if(x-1>=1&&check(x-1,y)) q[cnt++]=make_pair(x-1,y);
				if(y-1>=1&&check(x,y-1)) q[cnt++]=make_pair(x,y-1);
				if(x+1<=n&&check(x+1,y)) q[cnt++]=make_pair(x+1,y);
				if(y+1<=m&&check(x,y+1)) q[cnt++]=make_pair(x,y+1);
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		if(map[i][j]) ans+=1;
		printf("Case #%d:\n%d\n",ca++,ans);
	}
}

