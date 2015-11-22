#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
char map[61][61];
struct node{
	int x,pow,flag;
}num[5];
int pos=0;
void its(){
	memset(map,0,sizeof(map));
	memset(num,0,sizeof(num));
	pos=0;
	printf("                             y^                              \n");
	for(int i=0;i<61;++i){
		map[30][i]='-';
		map[i][30]='|';
	}
	map[30][30]='+';
}
void get(){
	char s[100];
	gets(s);
	if(s[2]!='-') s[1]=='+';
	int len=strlen(s),i=1;
	if(s[1]=='=') i+=1;
	while(i<len){
		if(s[i]==)
	}
}
void print(){
	int i,j;
	for(i=0;i<61;++i){
		printf("%s",map[i]);
		if(i==30) printf(">");
		if(i==31) printf("x");
		printf("\n");
	}
}
int main(){
	int t,ca=1;
	while(scanf("%d",&t)!=EOF){
		printf("Case:%d\n",ca++);
		its();
		get();
		print();
	}
}

