#include<iostream>
#include<string>
using namespace std;
struct clock{
	int h;
	char m[5];
	char am_pm[5];
};
int min(int a,int b){
	return a>b?b:a;
}
int abs(int x){
	return x>=0?x:-x;
}
int tonum(char s){
	return s-'0';
}
int main(){
	int n;
	scanf("%d%*c",&n);
	while(n--){
		clock ala[2];
		int ans=0;
		scanf("%d:%c%c%s",&ala[0].h,&ala[0].m[0],&ala[0].m[1],ala[0].am_pm);
		scanf("%d:%c%c%s",&ala[1].h,&ala[1].m[0],&ala[1].m[1],ala[1].am_pm);
		if(ala[0].am_pm[0]!=ala[1].am_pm[0]) ++ans;
		ans+=min(abs(ala[0].h-ala[1].h),12-abs(ala[0].h-ala[1].h));
		ans+=min(abs(tonum(ala[0].m[0])-tonum(ala[1].m[0])),6-abs(tonum(ala[0].m[0])-tonum(ala[1].m[0])));
		ans+=min(abs(tonum(ala[0].m[1])-tonum(ala[1].m[1])),10-abs(tonum(ala[0].m[1])-tonum(ala[1].m[1])));
		printf("Going from %d:%c%c%s to %d:%c%c%s requires %d push",ala[0].h,ala[0].m[0],ala[0].m[1],ala[0].am_pm,ala[1].h,ala[1].m[0],ala[1].m[1],ala[1].am_pm,ans);
		if(ans==1) printf(".\n");
		else printf("es.\n");
	}
}
