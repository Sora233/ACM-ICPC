#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
#define LL long long int
#define LLINF 0x7ffffffffffffff
using namespace std;
int gun[100005], mon[100005];
int erfen(int n, int m){
    int l = 0, r = min(n, m), mid;
    while( l < r ){
        mid = (l+r) >> 1;
        if( gun[mid] >= mon[mid] ) l = mid +1;
        else r = mid;
    }
    return l;
}
int main(){
    int T;
    scanf("%d", &T);
    while( T-- ){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; ++i) scanf("%d", &gun[i]);
        for(int i = 0; i < m; ++i) scanf("%d", &mon[i]);
        sort(gun, gun+n, greater<int>() );
        sort(mon, mon+m);
        int last = erfen(n, m);
        LL ans = 0;
        for(int i = 0; i < last; ++i){
            ans += gun[i] - mon[i];
        }
        printf("%lld\n", ans);
    }
}
