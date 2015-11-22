#include<stdio.h>
#include<string.h>
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
void  add(char a[],char b[],char c[]){  //不处理负数 
    Strrev(a);
    Strrev(b);
    int lena=strlen(a),lenb=strlen(b),len=lena>lenb?lena:lenb;
    for(int i=0;i<len;i++){
    c[i]+=tonum(a[i])+tonum(b[i])+'0';
    if(c[i]>'9') c[i]-=10,c[i+1]++;
    }
    if(c[len]&&c[len]<'0') c[len]+='0';
    Strrev(c);
    return;
}
int main(){
    int T;
    scanf("%d%*c",&T);
    char a[5005],b[5005],c[5005];
    for(int C=1;C<=T;C++){
        for(int i=0;i<5005;i++) a[i]=b[i]=c[i]=0;
        scanf("%s%s",a,b);
        printf("Case %d:\n%s + %s = ",C,a,b);
        add(a,b,c);
        printf("%s\n",c);
        if(C!=T) printf("\n");
    }
}
