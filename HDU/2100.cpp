#include<cstdio>
#include<cstring>
void Copy(char *a,char *b,int lena){
for(int i=0;i<lena;i++)
b[i]=a[lena-i-1];
}
void add(char *a,char *b,int len){
	while(len>=0){
	a[len]+=b[len--];
}
}
main(){
	char a[205],b[205],c[205],d[205];
	while(scanf("%s",a)!=EOF){
		scanf("%s",b);
		int lena=strlen(a);
		int lenb=strlen(b);
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		Copy(a,c,lena);
		Copy(b,d,lenb);
		int len=lena>lenb?lena:lenb;
		add(c,d,len-1);
		int i=0;
		while(i<205){
			if(c[i]>'Z') c[i]-=26,c[i+1]++;
			i++;
		}
		while(c[len]!='\0') len++;
		for(i=len-1;i>=0;i--)
		printf("%c",c[i]);
		printf("\n");
	}
}
