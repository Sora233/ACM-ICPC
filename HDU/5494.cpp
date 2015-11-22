#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    int a[505], b[505];
    while(T--){
        int n, m, sa = 0, sb = 0;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; ++i){
            scanf("%d", &b[i]);
        }
        sort(a, a+n);
        sort(b, b+n);
        for(int i = 0; i < m; ++i){
            sa += a[i];
            sb += b[n-1-i];
        }
        if(sa > sb) puts("YES");
        else puts("NO");
    }
}
