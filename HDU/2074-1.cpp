#include<cstdio>
#include<cstring>
main()
{
	char op[85][85],heart,out;
	int n,i,j,k;
	while(scanf("%d%*c",&n)!=EOF){
		for(i=0;i<85;i++)
		    for(j=0;j<85;j++)
		        op[i][j]='\0';
		scanf("%c%*c%c%*c",&heart,&out);
		for(k=0;k<(n+1)/2;k++)
		if(((n+1)/2-k)%2==0){
			for(i=k;;break)
		}
		printf("\n");
	}
	}
