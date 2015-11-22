#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
int count=0;
bool flag_md;
bool isnum(char c){
	if(c>='0'&&c<='9') return 1;
	return 0;
}
void getcount(char *exp){
	int len=strlen(exp),flag=0;
	flag_md=0;
	for(int i=0;i<len;i++){
		if(isnum(exp[i])&&!flag) ++count,flag=1;
		if(!isnum(exp[i])){
		flag=0;
		if(exp[i]=='*'||exp[i]=='/') flag_md=1;
	    }
	}
}
int getfront(char *exp,int pos){
	stack<int>s;
	int flag=0,val=0;
	for(int i=pos-1;i>=0;--i){
	if(isnum(exp[i])){
		flag=1;
		s.push(exp[i]-'0');
		exp[i]=' ';
	}
	if(flag&&!isnum(exp[i])) break;
    }
    while(!s.empty()){
		val=val*10+s.top();
		s.pop();
	}
	return val;
}
int getback(char *exp,int pos){
	int flag=0,val=0;
	for(int i=pos+1)
}
int main(){
	char exp[205];
	while(cin.getline(exp,205)){
		int len=strlen(exp);
		getcount(exp);
		while(count>1){
			if(flag_md){
				int pos;
				for(pos=0;pos<len;++pos)
				if(exp[pos]=='*'||exp[pos]=='/') break;
				int vala=getfront(exp,pos),valb=getback(exp,pos);
			}
		}
	}
}
