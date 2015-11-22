#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 100005;
int a[N], lisan[N];
int ls[N<<5], rs[N<<5], w[N<<5];
int root[N<<5], cnt;
int n, m;
void build(int &rt, int l, int r){
    rt = ++cnt; w[rt] = 0;
    if(l >= r) return;
    int m = (l+r) >> 1;
    build(ls[rt], l, m);
    build(rs[rt], m+1, r);
}
void update(int u, int &v, int l, int r, int x){
    v = ++cnt;
    ls[v] = ls[u], rs[v] = rs[u], w[v] = w[u] + 1;
    if(l >= r) return;
    int m = (l+r) >> 1;
    if(x <= m) update(ls[u], ls[v], l, m, x);
    else update(rs[u], rs[v], m+1, r, x);
}
int query(int u, int v, int l, int r, int k){
    if(l >= r) return l;
    int tmp = w[ls[v]] - w[ls[u]];
    int m = (l+r) >> 1;
    if(k <= tmp) return query(ls[u], ls[v], l, m, k);
    else return query(rs[u], rs[v], m+1, r, k-tmp);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            lisan[i] = a[i];
        }
        sort(lisan+1, lisan+n+1);
        int sz = unique(lisan+1, lisan+n+1) - lisan-1;
        root[0] = cnt = 0;
        build(root[0], 1, sz);
        for(int i = 1; i <= n; ++i){
            int tmp = lower_bound(lisan+1, lisan+sz+1, a[i]) - lisan;
            update(root[i-1], root[i], 1, sz, tmp);
        }
        int l, r, k;
        while(m--){
            scanf("%d %d %d", &l, &r, &k);
            int tmp = query(root[l-1], root[r], 1, sz, k);
            printf("%d\n", lisan[tmp]);
        }
    }
}
