#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long int
#define LLINF 0x7ffffffffffffff
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    while( T-- ){
        LL arr[1005], p, ans = -LLINF;
        int len;
        scanf("%d %lld", &len, &p);
        for(int i = 0; i < len; ++i) scanf("%lld", &arr[i]);
        for(int i = 0, j; i < len; ++i){
            LL mi = LLINF, sum = 0;
            for(j = i; j < len; ++j){
                mi = min(mi, arr[j]);
                sum += arr[j];
                if(mi < p) ans = max(ans, sum + p - mi);
                else if(i == 0 && j == len-1) ans = max(ans, sum + p - mi);
                else ans = max(ans, sum);
            }
        }
        printf("%lld\n", ans);
    }
}
