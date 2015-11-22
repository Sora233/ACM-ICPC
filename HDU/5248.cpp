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
int num[100005];
int ch[100005];
int n;
bool ok(int ma){
	ch[1]=num[1]-ma;
	for(int i=2;i<=n;++i){
		if(num[i]>ch[i-1]){
			ch[i]=max(num[i]-ma,ch[i-1]+1);
		}
		else if(num[i]<=ch[i-1]){
			ch[i]=min(num[i]+ma,ch[i-1]+1);
			if(ch[i]<=ch[i-1]) return 0;
		}
	}
	return 1;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&num[i]);
		int l=0,r=1000005,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(ok(mid)) r=mid;
			else l=mid+1;
		}
		printf("Case #%d:\n%d\n",ca++,l);
	}
}

