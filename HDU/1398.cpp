#include<stdio.h>
int main(){
	int c1[305],c2[305];
	int n,i,j,k;
		for(i=0;i<305;i++){
			c1[i]=1;
			c2[i]=0;
		}
		for(i=2;i*i<=304;i++)
		{
			for(j=0;j<=304;j++)
			for(k=0;k+j<=304;k+=i*i)
			c2[j+k]+=c1[j];
			for(j=0;j<=304;j++){
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
	while(scanf("%d",&n)!=EOF&&n!=0){
		printf("%d\n",c1[n]);
	}
}
