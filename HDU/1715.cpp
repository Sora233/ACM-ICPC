#include<stdio.h>
#include<string.h>
//未处理前导0 
void Strrev(char *a){
	int len=strlen(a);
	char temp;
	for(int i=0,j=len-1;i<len/2;i++,j--)
	temp=a[i],a[i]=a[j],a[j]=temp;
}
int tonum(char c){
	if(c>='0'&&c<='9') return c-'0';
	return 0;
}
void  add(char* const a,char* const b,char *c){  //不处理负数 
	memset(c,0,sizeof(c));
	Strrev(a);
	Strrev(b);
	int lena=strlen(a),lenb=strlen(b),len=lena>lenb?lena:lenb;
	for(int i=0;i<len;i++){
	c[i]+=tonum(a[i])+tonum(b[i])+'0';
	if(c[i]>'9') c[i]-=10,c[i+1]++;
    }
    if(c[len]&&c[len]<'0') c[len]+='0';
    Strrev(c);
    Strrev(a);
	Strrev(b);
    return;
}
char a[1005][1005];
int main(){
	memset(a,0,sizeof(a));
	a[1][0]='1';
	a[2][0]='1';
	for(int i=3;i<=1000;i++)
	add(a[i-2],a[i-1],a[i]);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		puts(a[n]);
	}
}
