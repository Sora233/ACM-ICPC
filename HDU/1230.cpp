#include<stdio.h>
#include<string.h>
int main(){
	int dicm[30]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
	char a[100],b[100];
	int c[100],d[100];
	while(scanf("%s%s",a,b)!=EOF){
		if(a[0]=='0'||b[0]=='0') break;
		int c[100],d[100],i,countc,countd;
		int lena=strlen(a),lenb=strlen(b);
		for(i=lena-1,countc=1;i>=0;i--)
		if(a[i]>='0'&&a[i]<='9') c[countc++]=a[i]-'0';
		for(i=lenb-1,countd=1;i>=0;i--)
		if(b[i]>='0'&&b[i]<='9') d[countd++]=b[i]-'0';
		int len=countc<countd?countc:countd;
		for(i=1;i<=len;i++){
			c[i]+=d[i];
			if(c[i]>dicm[i]) c[i]-=dicm[i],c[i+1]++;
		}
		if(c[i]) len++;
		for(i=len;i>=1;i--)
		printf("%d",c[i]);
		printf("\n");
	}
}
