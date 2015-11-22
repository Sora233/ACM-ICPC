#include<cstdio>
#include<cstring> 
main(){
	int n,top,i,j,k;
	char a[10],b[10],str[20][5];
	char stack[30];
	while(scanf("%d%s%s",&n,&a,&b)!=EOF){
		top=i=j=k=0;
		strcpy(str[k],"in");
		while(i<n){
			stack[top]=a[i];
		while(stack[top]==b[j]&&b[j]!='\0'){
			top--;
			j++;
			strcpy(str[++k],"out");
		}
		i++;
		top++;
		strcpy(str[++k],"in");
	}
	if(top==0){
		printf("Yes.\n");
		for(i=0;i<k;i++)
		puts(str[i]);
	}
	else printf("No.\n");
	printf("FINISH\n");
	memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(stack,0,sizeof(stack));
}
}
