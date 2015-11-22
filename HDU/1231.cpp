#include<iostream>
using namespace std;
int main(){
	int N;
	while(scanf("%d",&N)!=EOF&&N){
		int sum=0,t=0,max=-2147483647,start=0,end=0,num,num1,numed;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&num);
			if(!i) num1=num,t=num;
			else if(i==N-1) numed=num;
			if(sum>=0) sum+=num;
			else sum=num,t=num;
			if(sum>max) max=sum,end=num,start=t;
		}
		if(max<0) printf("0 %d %d\n",num1,numed);
		else printf("%d %d %d\n",max,start,end);
	}
}
