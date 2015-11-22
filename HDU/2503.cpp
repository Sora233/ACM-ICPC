#include<cstdio>
int gcd(int a,int b) //a>b;
{
	return !b?a:gcd(b,a%b);
}
main(){
	int a,b,c,d,r,t;
	int up,down;
	scanf("%d",&t);
	while(t--) {
	scanf("%d%d%d%d",&a,&b,&c,&d);
		down=b*d;
		up=a*d+b*c;
		r=up>down?gcd(up,down):gcd(down,up);
		printf("%d %d\n",up/r,down/r);
	}
}
