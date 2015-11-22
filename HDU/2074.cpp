#include<stdio.h>
#include<string.h>
main(){
	char heart,b,out,in,op[90][90];
	int n,len,i,j,leap=0,first=0;
	while(scanf("%d %c %c%*c",&n,&heart,&b)!=EOF){
		if(first)printf("\n");
		memset(op,0,sizeof(op));
		len=(n+1)/2;
		leap=0;
		i=0,j=0;
		if(len%2==0) out=b,in=heart;
		else out=heart,in=b;
		if(n!=1){
		op[0][0]=out;
		while(leap<=len){
			while(i+1<n&&op[i+1][j]==0) if(leap%2==0) op[++i][j]=out; else op[++i][j]=in;
			while(j+1<n&&op[i][j+1]==0) if(leap%2==0) op[i][++j]=out; else op[i][++j]=in;
			while(i>0&&op[i-1][j]==0) if(leap%2==0) op[--i][j]=out; else op[--i][j]=in;
			while(j>0&&op[i][j-1]==0) if(leap%2==0) op[i][--j]=out; else op[i][--j]=in;
			leap++;
		}
		op[0][0]=op[n-1][0]=op[0][n-1]=op[n-1][n-1]=' ';
		for(i=0;i<n;i++)
		puts(op[i]);
	}
	else printf("%c\n",heart);
	first++;
	}
}
