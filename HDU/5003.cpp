#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
double esp=0.95;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,soc[55]={0};
		double sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&soc[i]);
		sort(soc+1,soc+n+1,cmp);
		for(int i=1;i<=n;i++)
		sum+=soc[i]*pow(esp,i-1.0);
		printf("%.5f\n",sum);
	}
}
