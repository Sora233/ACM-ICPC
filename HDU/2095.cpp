#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[1000005];
bool iseven(int x){
	if(x&1) return 1;
	return 0;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		memset(a,0,sizeof(a));
		int ans=-1,count=0;
		for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
		sort(a,a+n);
		for(int i=0;i<=n;++i){
			if(a[i]!=ans) {
				if(iseven(count)){
				printf("%d\n",ans);
				break;
			    }
			    else ans=a[i],count=1;
			}
			else {
				++count;
			}
		}
	}
}
