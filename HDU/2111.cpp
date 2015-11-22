#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct th{
	int val;
	int vol;
};
th lag[105];
bool cmp(th a,th b){
	if(a.val!=b.val) return a.val>b.val;
	return a.vol>b.vol;
}
int main(){
	int v,kind;
	while(scanf("%d",&v)!=EOF){
		if(!v) break;
		scanf("%d",&kind);
		memset(lag,0,sizeof(lag));
		for(int i=0;i<kind;i++){
			scanf("%d%d",&lag[i].val,&lag[i].vol);
		}
		sort(lag,lag+kind,cmp);
		int sum=0,vol=0;
		for(int i=0;i<kind;i++){
			if(v-vol>lag[i].vol){
				sum+=lag[i].val*lag[i].vol;
				vol+=lag[i].vol;
			}
			else {
				sum+=lag[i].val*(v-vol);
				break;
			}
		}
		printf("%d\n",sum);
	}
}
