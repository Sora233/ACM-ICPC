#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[50001],b[50001],c[100001];
void mulitply(char a[],char b[],char c[]){
	if(a[0]=='0'||b[0]=='0'){
	c[0]='0',c[1]='\0';
	return;
    }
	int len_a=strlen(a),len_b=strlen(b),i,j;
    int *s=new int[len_a+len_b+5];
	memset(s,0,sizeof(int)*(len_a+len_b+5));
	for(i=0;i<len_a;i++)
		for(j=0;j<len_b;j++)
			s[i+j+1]+=(a[i]-'0')*(b[j]-'0');
	for(i=len_a+len_b-1;i>=0;i--)
		if(s[i]>=10){
			s[i-1]+=s[i]/10;
			s[i]=s[i]%10;
		}
		i=0;
		while(s[i]==0) i++;
		for(j=0;i<len_a+len_b;i++,j++)
			c[j]=s[i]+'0';
		c[j]='\0';
		delete []s;
}
int main(){
	while(scanf("%s%*c%s%*c",a,b)!=EOF){
		mulitply(a,b,c);
		puts(c);
	}
}
