#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}
int main(){
	int step,mod;
	while(scanf("%d%d",&step,&mod)){
		int flag=gcd(mod,step)==1?1:0;
		printf("%10d%10d",step,mod);
		if(flag) printf("%25s\n","Good Choice");
		else printf("%25s\n","Bad Choice");
		printf("\n");
	}
}
