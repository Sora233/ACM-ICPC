#include<cstdio>
#include<cmath>
#include<string.h>
using namespace std;
int main(){
	char a[20],b[20];
	while(scanf("%s%*c%s%*c",a,b)!=EOF){
		int lena=strlen(a),lenb=strlen(b),count=0,suma=0,sumb=0;
		for(int i=lena-1;i>=0;i--)
		if(a[i]>='0'&&a[i]<='9') suma+=(a[i]-'0')*(int)pow(10.0,(count++)*1.0);
		if(a[0]=='-') suma=-suma;
		for(int i=lenb-1,count=0;i>=0;i--)
		if(b[i]>='0'&&b[i]<='9') sumb+=(b[i]-'0')*(int)pow(10.0,(count++)*1.0);
		if(b[0]=='-') sumb=-sumb;
		printf("%d\n",suma+sumb);
	}
}
