#include<cstdio>
main()
{
	int dml,vml,time,i,sum;
	while(scanf("%d%d",&vml,&dml)!=EOF){
		time=vml,sum=0;
		for(i=1;sum<vml;i++){
			sum+=i;
			time++;
		}
		time--;
		printf("%d\n",time);
	}
}
