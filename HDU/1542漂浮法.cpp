#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
#include<ctime>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
int n;
double ans;
struct poi{
    double x,y;
}ld[105],rt[105];
void pf(double lx,double ly,double rx,double ry,int c){
    if(lx>=rx||ly>=ry)return;
    while(ly>=rt[c].y||lx>=rt[c].x||rx<=ld[c].x||ry<=ld[c].y) c+=1;
    if(c>=n){
        ans+=(rx-lx)*(ry-ly);
        return;
    }
    if(ld[c].y<=ly&&ld[c].x<=lx&&rt[c].x>=rx&&rt[c].y>=ry) return;
    if(ly<ld[c].y)pf(max(ld[c].x,lx),ly,max(ld[c].x,rx),min(ld[c].y,ry),c+1);
    if(ry>rt[c].y)pf(min(lx,rt[c].x),max(ly,rt[c].y),min(rt[c].x,rx),ry,c+1);
    if(lx<ld[c].x)pf(lx,min(rt[c].y,ly),min(ld[c].x,rx),min(rt[c].y,ry),c+1);
    if(rx>rt[c].x)pf(max(rt[c].x,lx),max(ld[c].y,ly),rx,max(ld[c].y,ry),c+1);
}
int main(){
    int ca=1;
    while(scanf("%d",&n)!=EOF&&n){
        ans=0;
        for(int i=0;i<n;++i) scanf("%lf%lf%lf%lf",&ld[i].x,&ld[i].y,&rt[i].x,&rt[i].y);
        for(int i=0;i<n;++i) pf(ld[i].x,ld[i].y,rt[i].x,rt[i].y,i+1);
        printf("Test case #%d\nTotal explored area: %.2f\n\n",ca++,ans);
    }
}
