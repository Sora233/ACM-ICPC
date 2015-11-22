#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<string>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
const double esp=1e-3;
struct sprit{
    double pos;
    double wei;
}sp[50005];
double bound;
int n;
double cal(double pos){
    double res=0;
    for(int i=0;i<n;++i)
        res+=fabs((sp[i].pos-pos)*(sp[i].pos-pos)*(sp[i].pos-pos))*sp[i].wei;
    return res;
}
int main(){
    int T,ca=1;
    scanf("%d",&T);
    while(T--){
        double l=1e50,r=-1e50;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%lf%lf",&sp[i].pos,&sp[i].wei);
            r=max(r,sp[i].pos);
            l=min(l,sp[i].pos);
        }
        double mid,midmid,midv=1,midmidv=10;
        while(fabs(midv-midmidv)>=esp){
            mid=(l+r)/2;
            midmid=(mid+r)/2;
            midv=cal(mid),midmidv=cal(midmid);
            if(midv<midmidv) r=midmid;
            else l=mid;
        }
        printf("Case #%d: %.0f\n",ca++,midv);
    }
}
