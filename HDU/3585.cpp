#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int n,k;
struct node{
	int x,y;
}p[55];
struct Ans{ 
	int num1,num2;//记录最近点的坐标 
	double dis; //维护最近距离 
	node c[55];
	bool v[55];
}ans[20];
double dis[10000];
double Dis(node a,node b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
void rand(Ans p){
	
}
void SA(){
	doble tmper=n+k,esp=1e-2;
	for)
}
int main(){
	srand(unsigned(time(0)));
	while(scanf("%d%d",&n,&k)!=EOF){
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;++i){
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		SA();
	}
}

