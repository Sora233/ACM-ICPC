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
int l[2005],lcort,r[2005],rcort;
int main(){
    int n,t;
    while(scanf("%d%d",&n,&t)!=EOF){
        int tmp,ans=-0xfffffff,lma=0xfffffff,rma=-0xfffffff;
        lcort=rcort=0;
        for(int i=0;i<n;++i) {
            scanf("%d",&tmp);
            if(tmp>=0) {
                r [rcort++]=tmp;
                if(tmp<=T&&tmp>=rma) rma=i
            }
            else {
                l [lcort++]=tmp;
            }
        }
        sort(l,l+lcort,greater<int>());
        sort(r,r+rcort);
        for(int i=0;i<lcort&&i<rcort&&(-l [i]<=t||r [i]<=t);++i){
            if(-l [i]<=t) ans=max(ans,i+1);
            if(r [i]<=t) ans=max(ans,i+1);
        }
    }
}
