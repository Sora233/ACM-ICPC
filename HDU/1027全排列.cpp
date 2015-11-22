#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1005];
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=0;i<n;++i) a[i]=i+1;
		for(int i=1;i<m;++i) next_permutation(a,a+n);
		for(int i=0;i<n;++i) if(!i) printf("%d",a[i]); else printf(" %d",a[i]);
		printf("\n");
	}
}
