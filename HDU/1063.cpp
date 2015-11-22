#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cmath>
char a[1000000];
void multiply(char* a,char* c)
{
    int i,j,ca,* s;
    ca=strlen(a);
    s=(int*)calloc(ca+ca,sizeof(int));
    for (i=0;i<ca;i++)
        for (j=0;j<ca;j++)
            s[i+j+1]+=(a[i]-'0')*(a[j]-'0');
    for (i=ca+ca-1;i>=0;i--)
        if (s[i]>=10)
        {
            s[i-1]+=s[i]/10;
            s[i]%=10;
        }
    i=0;
    while (s[i]==0)
        i++;
       for (j=0;i<ca+ca;i++,j++)
           c[j]=s[i]+'0';
    c[j]='\0';
    free(s);
}
int sFind(char *a){
	int pos,count=0,i,len=strlen(a);
	for(i=len-1;i>=0;i--,count++)
	if(a[i]=='.')  break;
	for(i++;i<len;i++)
	a[i-1]=a[i];
	a[len-1]='\0';
	return count;
}
int main(){
	int times;
	while(fgets(a,7,stdin)!=NULL){
		int count=sFind(a);
		scanf("%d",&times);
		for(int i=2;i<=times;i++)
		multiply(a,a);
		int len=strlen(a),flag;
		count=(int)pow(count*1.0,times*1.0);
		flag=len-count;
		for(int i=0;i<len;i++){
			if(i==flag) printf(".%c",a[i]);
			else printf("%c",a[i]);
		}
		printf("\n");
	}
}
