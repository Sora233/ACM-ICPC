#include<stdio.h>
int main(){
	int a,b,n;
	while(scanf("%d%d%d",&a,&b,&n)!=EOF){
		if(!a&&!b&&!n) break;
		int num[55]={0,1,1};
		for(int i=3;i<=50;i++){
			num[i]=(a*num[i-1]+b*num[i-2])%7;
		}
		if(n>48) n%=48;
		printf("%d\n",num[n]);
	}
}
