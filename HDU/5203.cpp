#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;
int n, m;
int a[1005];
int len[1015], cnt;
int main(){
    while( scanf("%d %d", &n, &m) != EOF ){
        for(int i = 1; i <= m; ++i)
            scanf("%d", &a[i]);
        sort(a+1, a +m +1);
        m = unique(a+1, a +m +1) - (a+1);
        a[0] = 1, cnt = 0, a[m+1] = n;
        for(int i = 1; i <= m+1; ++i){
            len[cnt++] = a[i] - a[i-1];
        }
        sort(len, len +cnt, greater<int>() );
        for(int i = 0; i < cnt; ++i) printf("lenth=%d\n", len[i]);
    }
}
