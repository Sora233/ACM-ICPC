#include<cstdio>
#include<cstring>
long long int tot[21];
long long int num[21];
int flag[21];
int main(){
	tot[1]=1;
	num[1]=1;
	for(int i=2;i<21;i++){
	tot[i]=(tot[i-1]+1)*i;
	num[i]=tot[i]/i;
}
	long long int m;
	int n;
	while(scanf("%d%lld",&n,&m)!=EOF){
		memset(flag,0,sizeof(flag));
		for(int i=n;i>=1;i--){
			long long int k=m;
			int count=1;
			while(k>num[i]) k-=num[i],count++;
			if(i==1&&n!=1&&m!=1){
				int count1=1;
				while(flag[count1])count1++;
				printf(" %d",count1);
				continue;
			}
		if(i==n) {
			printf("%d",count);
			flag[count]=1;
		}
		else if(count!=1) {
			while(flag[count-1]) count++;
		printf(" %d",count-1);
		flag[count-1]=1;
	}
	m-=(count-1)*num[i];
		}
		printf("\n");
	}
}
