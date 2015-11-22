#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
char a[1005],b[1005];
int Next[1005]={0},lena,lenb;
void gnext(){
	lena=strlen(a),lenb=strlen(b);
	Next[0]=-1;
	int j=0,k=-1;
	while(j<lenb)
		if(k==-1||b[j]==b[k])
			Next[++j]=++k;
		else k=Next[k];
	Next[lenb]=0;
}
int kmp_index(){
	gnext();
	int i=0,j=0;
	while(i<lena&&j<lenb){
		if(j==-1||a[i]==b[j]) ++j,++i;
		else j=Next[j];
	}
	if(j==lenb) return i-lenb+1;
	return -1;
}
int kmp_count(){
	int ans=0;
	gnext();
	int i=0,j=0;
	while(i<lena){
		if(j==-1||a[i]==b[j]) ++i,++j;
		else j=Next[j];	
		if(j==lenb) ans+=1;
	}
	return ans;
}
int main(){
	while(scanf("%s",a)){
		if(a[0]=='#') break;
		scanf("%s",b);
		printf("%d\n",kmp_count());
	}
}

