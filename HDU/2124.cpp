#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int L,N;
	while(scanf("%d%d",&L,&N)!=EOF){
		int a[605];
		for(int i=0;i<N;i++)
		scanf("%d",&a[i]);
		sort(a,a+N);
		int count=0;
		for(int i=N-1;i>=0;i--){
			if(L>a[i]) count++,L-=a[i];
			else {
				L=0;
				count++;
				break;
			}
		}
		if(L) printf("impossible\n");
		else printf("%d\n",count);
	}
}
