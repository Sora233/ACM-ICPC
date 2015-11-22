#include<stdio.h>
int get(void){
	char op[20];
	int i=0,count=0;
	int shi=0,ge=0;
	op[0]=getchar();
	while(op[i]!='+'&&op[i]!='='){
		i++;
		scanf("%c",&op[i]);
	}
	op[i]='\0';
	i=0;
	while(op[i]!='\0'){
		if(op[i]==' ') {
		count++;
	}
		i++;
	}
	if(count==1){
		if(op[0]=='z') return 0;
		if(op[0]=='o') return 1;
		if(op[0]=='t'&&op[1]=='w') return 2;
		if(op[0]=='t'&&op[1]=='h') return 3;
		if(op[0]=='f'&&op[1]=='o') return 4;
		if(op[0]=='f'&&op[1]=='i') return 5;
		if(op[0]=='s'&&op[1]=='i') return 6;
		if(op[0]=='s'&&op[1]=='e') return 7;
		if(op[0]=='e') return 8;
		if(op[0]=='n') return 9;
	}
	else if(count==2){
		if(op[0]=='z') shi=0;
		if(op[0]=='o') shi=1;
		if(op[0]=='t'&&op[1]=='w') shi=2;
		if(op[0]=='t'&&op[1]=='h') shi=3;
		if(op[0]=='f'&&op[1]=='o') shi=4;
		if(op[0]=='f'&&op[1]=='i') shi=5;
		if(op[0]=='s'&&op[1]=='i') shi=6;
		if(op[0]=='s'&&op[1]=='e') shi=7;
		if(op[0]=='e') shi=8;
		if(op[0]=='n') shi=9;
		i=0;
		while(op[i]!=' '){
			i++;
		}
		i++;
		if(op[i]=='z') ge=0;
		if(op[i]=='o') ge=1;
		if(op[i]=='t'&&op[i+1]=='w') ge=2;
		if(op[i]=='t'&&op[i+1]=='h') ge=3;
		if(op[i]=='f'&&op[i+1]=='o') ge=4;
		if(op[i]=='f'&&op[i+1]=='i') ge=5;
		if(op[i]=='s'&&op[i+1]=='i') ge=6;
		if(op[i]=='s'&&op[i+1]=='e') ge=7;
		if(op[i]=='e') ge=8;
		if(op[i]=='n') ge=9;
		return shi*10+ge;
	}
}
int main()
{
	int a=0,b=0,t=5;
	while(t){
	a=get();
	getchar();
	b=get();
	getchar();
	printf("%d\n",a+b);
	a=b=0;
}
	return 0;
}
