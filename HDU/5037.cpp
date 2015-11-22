#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int rock[200005];
int main(){
	int T;
	scanf("%d",&T);
	for(int ca=1;ca<=T;++ca){
		int rocknum,bank,jump,x,count=0,i,now=0,last=0;
		memset(rock,0,sizeof(rock));
		scanf("%d%d%d",&rocknum,&bank,&jump);
		for(i=1;i<=rocknum;++i)
			scanf("%d",&rock[i]);
		rock[++rocknum]=bank,rock[0]=0;
		sort(rock,rock+rocknum);
		last=jump;
		for(i=1;i<=rocknum;++i){
			int x=(rock[i]-rock[i-1])/(jump+1);
			int y=(rock[i]-rock[i-1])%(jump+1);
			if(last+y>=jump+1){
				last=y;
				count+=(x*2+1);
			}
			else{
				last+=y;
				count+=x*2;
			}
		}
		printf("Case #%d: %d\n",ca,count);
	}
}
