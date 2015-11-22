#include<cstdio>
#include<algorithm>
#include<iostream>
int main(){
    int T;
    scanf("%d", &T);
    while( T--){
        int n, m, p, q;
        scanf("%d %d %d %d", &n, &m, &p, &q);
        if( p*m <= q){
            printf("%d\n", n*p);
        }
        else{ // p*m > q
            int ans = n/m*q;
            if( (n%m)*p <= q ) ans += (n%m)*p;
            else ans += q;
            printf("%d\n", ans);
        }
    }
}
