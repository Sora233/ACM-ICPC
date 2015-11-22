#include<stdio.h>
int re(int a,int b){
	int t=a-b;
	if(t<0) t=-t;
	if(t>=5) t=9-t;
	return t;
}
int main(){
	int T;
	scanf("%d%*c",&T);
	while(T--){
		char s[5],e[5];
		gets(s);
		gets(e);
		int min=0;
		for(int i=0;i<4;i++)
		min+=re(s[i]-'0',e[i]-'0');
		printf("%d\n",min);
	}
}
