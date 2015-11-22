#include<stdio.h>
int main(){
	int s,e;
	while(scanf("%d%d",&s,&e)!=EOF){
		int max=0,t,flag=0;
		if(s>e)
			t=s,s=e,e=t,flag=1;
		for(int i=s;i<=e;i++){
			int j=i,count=1;
			while(j!=1){
				if(j%2==1) j=j*3+1;
				else j/=2;
				count++;
			}
			if(count>max) max=count;
		}
		if(!flag)printf("%d %d %d\n",s,e,max);
		else printf("%d %d %d\n",e,s,max);
	}
	return 0;
}
