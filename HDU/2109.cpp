#include<stdio.h>
#include<algorithm>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(!n) break;
		int a[101]={0},b[101]={0};
		int a_soc=0,b_soc=0;
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
		std::sort(a,a+n);
		std::sort(b,b+n);
		for(int i=0;i<n;i++)
		if(a[i]>b[i]) a_soc+=2;
		else if (a[i]==b[i]) a_soc++,b_soc++;
		else b_soc+=2;
		printf("%d vs %d\n",a_soc,b_soc);
	}
}
