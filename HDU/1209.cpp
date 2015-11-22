#include<stdio.h>
#include<cmath>
#include<string.h>
#include<algorithm>
using namespace std;
const double ESP=1e-9;
struct ang{
	int h,m;
	double angel;
};
ang test[5];
bool cmp(ang a,ang b){
	if(fabs(a.angel-b.angel)>ESP) return b.angel>a.angel;
	return b.h>a.h;
}
void quicksort(ang *test,int l,int r){
	if(l<r){
		ang x=test[l];
		int i=l,j=r;
	while(i<j){
		while(i<j&&cmp(x,test[j])) j--;
		if(i<j) test[i++]=test[j];
		while(i<j&&!cmp(x,test[i])) i++;
		if(i<j) test[j--]=test[i];
    }
        test[i]=x;
        quicksort(test,l,j-1);
        quicksort(test,i+1,r);
	}
}
int main(){
	//freopen("1209.in","r",stdin);
	int T;
	scanf("%d%*c",&T);
	while(T--){
		memset(test,0,sizeof(test));
		for(int i=0;i<5;i++){
			char se[100];
		scanf("%d:%d",&test[i].h,&test[i].m);
		getchar();
		int h=test[i].h,m=test[i].m;
		if(h>=12) h-=12;
		test[i].angel=fabs((h*1.0+m*1.0/60.0)*30.0-m*6.0);
		while(test[i].angel>360) test[i].angel-=360;
		if(test[i].angel>180) test[i].angel=360-test[i].angel;
	}
	quicksort(test,0,4);
	printf("%02d:%02d\n",test[2].h,test[2].m);
	}
}
