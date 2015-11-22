#include<stdio.h>
#include<string.h>
int a[32005];
int c[16005];
struct po{
	int x,y;
}point;
int lowbit(int x){
	return x&(-x);
};
int getsum(int pos){
	int sum=0;
	while(pos>0){
		sum+=a[pos];
		pos-=lowbit(pos);
	}
	return sum;
}
void update(int pos,int val){
	while(pos<32005){
		a[pos]+=val;
		pos+=lowbit(pos);
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			scanf("%d%d",&point.x,&point.y);
			point.x+=1,point.y+=1;
			update(point.x,1);
			int count=getsum(point.x)-1;
			c[count]++;
		}
		for(int i=0;i<n;i++)
		printf("%d\n",c[i]);
	}
}
