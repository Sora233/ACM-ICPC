#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;
struct po{
	double x,y,val;
}pot[51]; //50个点模拟减少误差
double X,Y;
int M;
double holex[1005],holey[1005];
double dis(po a,double x,double y){
	return (a.x-x)*(a.x-x)+(a.y-y)*(a.y-y);
}
double Evaluate(po tt) //返回到最近的洞的距离
{
    double Min=1e8;
    for (int i=1;i<=M;i++)
        if (dis(tt,holex[i],holey[i])<Min)
		    Min=dis(tt,holex[i],holey[i]);
    return Min;
}
void rand(po *a){
	a->x=((rand()%1000+1)*1.0/1000.00)*X;
	a->y=((rand()%1000+1)*1.0/1000.00)*Y;
	a->val=Evaluate(*a);
}
void SA(){ //分块并行模拟退火
	double temper=X+Y,eps=1e-5,dx,dy;
	po tmp;
	for(int i=1;i<=50;++i) rand(&pot[i]);  //随机一个初始位置
	while(temper>eps){
		for(int i=1;i<=50;++i)
			for(int j=1;j<=50;++j){
				dx=(double)(rand()%1000+1)*1.0/1000.0*temper;
                dy=sqrt(temper*temper-dx*dx);
				if (rand()&1) dx*=-1;
                if (rand()&1) dy*=-1;
				tmp.x=pot[i].x+dx;
				tmp.y=pot[i].y+dy;
				tmp.val=Evaluate(tmp);
				if(tmp.x>=0&&tmp.x<=X&&tmp.y>=0&&tmp.y<=Y&&tmp.val>pot[i].val) 	pot[i]=tmp;
		    }
		temper*=0.618;
	}
	int ans=1;
	for(int i=2;i<=50;++i)
	if(pot[ans].val<pot[i].val) ans=i;
	printf("The safest point is (%.1lf, %.1lf).\n",pot[ans].x,pot[ans].y);
}
int main(){
	srand(unsigned(time(0)));
	int T;
	cin>>T;
	while(T--){
		cin>>X>>Y>>M;
		for(int i=1;i<=M;++i)
		cin>>holex[i]>>holey[i];
		SA();
	}
}
