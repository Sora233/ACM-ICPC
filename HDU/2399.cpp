#include<cstdio>
#include<cstring>
main()
{
	char s[1000];
	int count,l,flag=0;
	double sum;
	while(gets(s)!=NULL){
		count=sum=flag=0;
		l=strlen(s)-1;
		while(l>=0){
			if(s[l]=='A') sum+=4,count++;
			else if(s[l]=='B') sum+=3,count++;
			else if(s[l]=='C') sum+=2,count++;
			else if(s[l]=='D') sum++,count++;
			else if(s[l]=='F') count++;
			else if(s[l]!=' '){
				printf("Unknown letter grade in input\n");
				flag=1;
				break;
			}
			l--;
		}
		if(flag!=1)printf("%.2f\n",sum/count);
	}
}
