#include<iostream>
#include<algorithm>
using namespace std;
int man[100005];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&(n||m)){
		for(int i=0;i<n;++i)
		scanf("%d",&man[i]);
		sort(man,man+n);
		for(int i=n-1,count=0;count<m;--i,++count)
		if(i==n-1) printf("%d",man[i]);
		else printf(" %d",man[i]);
		printf("\n");
	}
}
