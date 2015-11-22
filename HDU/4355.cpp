#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<string>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
double bound;
struct sprit{
    double pos;
    double W;
}sp[50005],ans[50];
int n;
void cal(sprit &a){
    a.W=0;
    for(int i=0;i<n;++i) a.W+=fabs((sp[i].pos-a.pos)*(sp[i].pos-a.pos)*(sp[i].pos-a.pos)*sp[i].W);
}
void rand(sprit &a){
    a.pos=(rand()%((int)(bound)));
    if(rand()&1) a.pos*=-1;
    cal(a);
}
void SA(){
    double tempr=n*2,esp=1e-2,dp,G;
    sprit temp;
    for(int i=0;i<n;++i) G+=sp[i].pos;
    G/=n;
    for(int i=0;i<30;++i) ans[i].pos=G+rand()%(int)n;
    while(tempr>esp){
        for(int i=0;i<30;++i){
            dp=rand()/n*tempr;
            if(rand()&1) dp*=-1;
            temp.pos=ans[i].pos+dp;
            if(fabs(temp.pos)>bound) continue;
            cal(temp);
            if(fabs(temp.pos)<=bound&&temp.W<ans[i].W) ans[i]=temp;
        }
        tempr*=0.75;
    }
}
int main(){
    srand(1);
    int T,ca=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        bound=0;
        for(int i=0;i<n;++i) {
                scanf("%lf %lf",&sp[i].pos,&sp[i].W);
                bound=max(fabs(sp[i].pos),fabs(bound));
        }
   //     printf("bound=%.3f\n",bound);
        SA();
        int min=0;
        for(int i=1;i<30;++i) if(ans[min].W>ans[i].W) min=i;
        printf("Case #%d: %lld\n",ca++,(LL)(ans[min].W+0.4));
    }
}
