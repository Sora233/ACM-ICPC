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
const double esp=1e-9;
struct fd{
    double J,F;
}food[1005];
int cmp(fd a,fd b){
    return a.J/a.F>b.J/b.F;
}
int main(){
    int n;
    double m;
    while(scanf("%lf%d",&m,&n)!=EOF&&(m!=-1||n!=-1)){
        if(n==0){
            printf("0.000\n");
            continue;
        }
        for(int i=0;i<n;++i)
            scanf("%lf%lf",&food[i].J,&food[i].F);
        sort(food,food+n,cmp);
        double ans=0;
        int i=0;
        for(int i=0;i<n;++i){
            if(m>=food[i].F) ans+=food[i].J,m-=food[i].F;
            else ans+=m*(food[i].J/food[i].F),m=0;
        }
        printf("%.3f\n",ans);
    }
}
