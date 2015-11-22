#include<cstdio>
#include<cstring>
main(){
	char a[1500],b[1500];
	while(scanf("%s",a)!=EOF&&a[0]!='#'){
		scanf("%s",b);
		int i=0;
		int la=strlen(a);
		int lb=strlen(b);
		int count=0;
		while(i+lb<=la){
			if(strncmp(a+i,b,lb)==0){
				count++;
				i+=lb;
				continue;
			}
			i++;
			}
			printf("%d\n",count);
		}
}
