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
int mat[35][35];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i) for(int j=0;j<n;++j) scanf("%d",&mat[i][j]);
		int ans=n;
		for(int i=0;i<n;++i){
			for(int j=0;j<=i;++j)
				if(mat[i][j]) ans+=1;
		}
		printf("%d\n",ans*2);
	}
}
