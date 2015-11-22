#include<stdio.h>
#include<string.h>
int main(){
	char s[105];
	while(scanf("%s",s)!=EOF){
		if(s[0]=='0'&&s[1]=='\0') break;
		int len=strlen(s),pos=0;
		for(int i=1;i<len;i++)
		if(s[pos]>=s[i]) pos=i;
		puts(s+pos);
	}
}
