#include<stdio.h>
#include<math.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		double r,ans;
		scanf("%d",&n);
		r=log(n%10);
		ans=fmod(r*n,10); 
		ans=floor(exp(ans));
		printf("%.0f\n",ans);
	}
}
