#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
#define ll long long int
using namespace std;
const double esp=1e-5;
double rs(double x){
	return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}
int main(){
	int t;
	double y,res;
	ll up,low,mid;
	scanf("%d",&t);
	while(t--){
		double y;
		scanf("%lf",&y);
		if(y<6||y>807020306) {
			printf("No solution!\n");
			continue;
		}
		up=10000000000,low=0;
		while(low<up){
			mid=(up+low)/2;
			res=rs(mid/100000000.0);
			if(fabs(res-y)<esp) break;
			if(res>y) up=mid-1;
			else low=mid+1;
		}
		if(low>up) printf("No solution!\n");
		else printf("%.4f\n",(double)mid/100000000.0);
	}
}

