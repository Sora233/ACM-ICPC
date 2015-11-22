#include<stdio.h>
#include<algorithm>
int a[1000001];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		std::sort(a,a+n);
		for(int i=n-1,count=0;;i--){
			if(i==n-1)printf("%d",a[i]);
			else printf(" %d",a[i]);
			count++;
			if(count==m) break;
		}
		printf("\n");
	}
}
