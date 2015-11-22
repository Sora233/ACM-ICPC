#include<cstdio>
#include<algorithm>
using namespace std;
int stn[500005],n,m;
int rive;
bool ok(int ma){
    int now=stn[0],t=0;
    for(int i=1;i<=n+1;t+=1){
        if(stn[i]-now>ma || t>=m) return 0;
        int p=upper_bound(stn,stn+n+2, now+ma) - stn;
        now=stn[p-1];
        i=p;
    }
    return 1;
}
int main(){
    while(scanf("%d%d%d",&rive,&n,&m)!=EOF){
        for(int i=1;i<=n;++i) scanf("%d",&stn[i]);
        sort(stn+1,stn+n+1);
        stn[0]=0,stn[n+1]=rive;
        int l=0,r=1000000005,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(ok(mid)) r=mid;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
}
