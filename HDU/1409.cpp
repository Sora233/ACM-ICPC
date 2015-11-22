#include<stdio.h>
#include<string.h>
bool isnum(char s){
	if(s>='0'&&s<='9') return 1;
	return 0;
}
int main(){
	int T;
	scanf("%d%*c",&T);
	while(T--){
		int flag=1;
		char s[105];
		gets(s);
		int len=strlen(s),i;
		int flag1=0,flag2=0,pos1,pos2;
		if(s[0]=='+'||s[0]=='-') s[0]='0';
		for(i=0;i<len;i++)
		if(s[i]=='.'){
			if(flag1){
			flag=0;
			break;
		    }
		    flag1=1;
		    pos1=i;
	    }
		else if(s[i]=='E') {
			if(i==0){
				flag=0;
				break;
			}
			if(flag2){
			flag=0;
			break;
		    }
		    flag2=1;
		    pos2=i;
	    }
	    else if(flag2&&s[i]=='-'){
	    	if(i!=pos2+1) {
	    		flag=0;
	    		break;
	    	}
	    }
		else if(!isnum(s[i])) {
			flag=0;
			break;
		}
		if(flag2){
			if(s[pos2+1]!='-'&&s[pos2+1]!='+'&&!isnum(s[pos2+1])) flag=0;
			if(flag1&&pos1>pos2) flag=0;
		}
		if(!flag) printf("NO\n");
		else printf("YES\n");
	}
}
