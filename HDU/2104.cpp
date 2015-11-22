#include<stdio.h>
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(m==-1&&n==-1) break;
		int r;
		while(m){
			r=n%m;
			if(r==0) break;
			n=m;
			m=r;
		}
		if(m==1) printf("YES\n");
		else printf("POOR Haha\n");
	}
}
