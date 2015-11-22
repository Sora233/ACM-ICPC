#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
char a[100005],b[100005];
int lena,lenb,Next[100005],pos;
void gNext(char b[]){
	int j=0,k=-1;
	Next[0]=-1,pos=-1;
	while(j<lenb){
		if(k==-1||b[j]==b[k]) Next[++j]=++k;
		else k=Next[k];
	}
}
int max(int a,int b){
	return a>b?a:b;
}
int kmp(char a[],char b[],int lena,int lenb){
	int j=0,i=0;
	gNext(b);
	while(i<lena&&j<lenb){
		if(j==-1||a[i]==b[j]){
			++i,++j;
		}
		else j=Next[j];
	}
	if(i<lena||(j==lenb&&i==lena)) return i;
	return 0;
}
int main(){
	while(scanf("%s%s",a,b)!=EOF){
		int lena=strlen(a),lenb=strlen(b);
		int la=kmp(a,b,lena,lenb),lb=kmp(b,a,lenb,lena);
		if(la>lb||(la==lb&&strcmp(a,b)<0)){
			printf("%s%s\n",a,b+la);
		}
		else printf("%s%s\n",b,a+lb);
	}
}

