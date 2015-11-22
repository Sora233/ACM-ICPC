#include<stdio.h>
int main(){
	int a[35][35],n;
	for(int i=0;i<=30;i++)
	a[1][1]=a[i][0]=a[i][i]=1;
	for(int i=2;i<=30;i++)
	for(int j=1;j<i;j++)
	a[i][j]=a[i-1][j]+a[i-1][j-1];
	while(~scanf("%d",&n)){
	for(int i=0;i<n;i++){
		printf("%d",a[i][0]);
		for(int j=1;j<=i;j++){
			printf(" %d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	}
	return 0;
}
