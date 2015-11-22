#include<map>
#include<string>
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
int maz[15][15],flag;
pii nex(pii now){
	int y=now.first,x=now.second;
	if(y==1) return make_pair(9,x-1);
	return make_pair(y-1,x);
}
bool ok(int val,int y,int x){
	for(int i=1;i<=9;++i){
		if(maz[i][x]==val) return 0;
		if(maz[y][i]==val) return 0;
	}

	int lx,rx,ly,ry;
	if(y>=1&&y<=3) ly=1,ry=3;
	else if(y>=4&&y<=6) ly=4,ry=6;
	else ly=7,ry=9;
	if(x>=1&&x<=3) lx=1,rx=3;
	else if(x>=4&&x<=6) lx=4,rx=6;
	else lx=7,rx=9;
	for(int i=ly;i<=ry;++i){
		for(int j=lx;j<=rx;++j){
			if(maz[i][j]==val) return 0;
		}
	}
	return 1;
}
void dfs(pii now){
	int y=now.first,x=now.second;
	if(y==9&&x==0){
		flag=1;
		return;
	}
	if(maz[y][x]!=0) dfs(nex(now));
	else {
		for(int i=1;i<=9;++i){
			if(ok(i,y,x)){
				maz[y][x]=i;
				dfs(nex(now));
				if(flag) return;
				maz[y][x]=0;
			}
		}
	}
}
int main(){
	int f=0;
	char p;
	while(scanf("%c%*c",&p)!=EOF){
		maz[1][1]= (p=='?')? 0:p-'0';
		for(int i=1;i<=9;++i){
			for(int j=1;j<=9;++j){
				if(i==1&&j==1) continue;
				scanf("%c%*c",&p);
				maz[i][j]= (p=='?')? 0:p-'0';
			}
		}
		getchar();
		flag=0;
		if(f) printf("\n");
		else f=1;
		dfs(make_pair(9,9));
		for(int i=1;i<=9;++i){
			for(int j=1;j<=9;++j){
				if(j==1) printf("%d",maz[i][j]);
				else printf(" %d",maz[i][j]);
			}
			printf("\n");
		}
	}
}
