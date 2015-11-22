#include<stdio.h>
#include<cstring>
int Find(char *a){
	int i=0;
	while(a[i]!='\0'){
		if(a[i++]=='.') return 1;
	}
	return 0;
}
int main(){
	char a[50000],b[50000];
	while(scanf("%s%s",a,b)!=EOF){
	int s_a,e_a,s_b,e_b,len_a,len_b;
	int flag_a,flag_b;
	len_a=strlen(a);
	len_b=strlen(b);
	if((len_a==2&&len_b==1&&a[0]=='-'&&a[1]=='0'&&b[0]=='0')||(len_b==2&&len_a==1&&b[0]=='-'&&b[1]=='0'&&a[0]=='0')){
	printf("YES\n");
	continue;
	}
	if((a[0]=='-'&&b[0]!='-')||(b[0]=='-'&&a[0]!='-')){
		printf("NO\n");
		continue;
	}
	for(s_a=0;s_a<len_a;s_a++){
		if(a[s_a]=='+') s_a++;
	if(a[s_a]!='0')break;
}
	for(s_b=0;s_b<len_b;s_b++){
		if(b[s_b]=='+') s_b++;
	if(b[s_b]!='0')break;
}
	flag_a=Find(a);
	flag_b=Find(b);
	e_a=len_a-1;
	e_b=len_b-1;
	if(flag_a)for(;e_a>=s_a;e_a--){
	if(a[e_a]!='0'&&a[e_a]!='.')break;
	if(a[e_a]=='.'){
	e_a--;
	break;
}
}
	if(flag_b)for(;e_b>=s_b;e_b--){
	if(b[e_b]!='0'&&b[e_b]!='.')break;
	if(b[e_b]=='.'){
	e_b--;
	break;
}
}
	if(e_a-s_a!=e_b-s_b) printf("NO\n");
	else{
		if(!strncmp(a+s_a,b+s_b,e_b-s_b+1)) printf("YES\n");
		else printf("NO\n");
	}
	}
}
