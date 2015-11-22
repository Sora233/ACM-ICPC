#include<algorithm>
#include<cstdio>
#define lson(i) tree[i].l
#define rson(i) tree[i].r
using namespace std;
const int N = 100005;
int n, m;
int a[N], lisan[N];
struct node{
    int l, r, w;
    node(){ l = r = w = 0; }
}tree[N*20];
int root[N], cnt;
void build(int &rt, int l, int r, int x){
    tree[++cnt] = tree[rt]; rt = cnt;
    tree[rt].w += 1;
    if(l == r) return;
    int m = (l+r) >> 1;
    if(x <= m) build(lson(rt), l, m, x);
    else build(rson(rt), m+1, r, x);
}
int query(int u, int v, int l, int r, int k){
    if(l >= r) return l;
    int tmp = tree[lson(v)].w - tree[lson(u)].w;
    int m = (l+r) >> 1;
    if(k <= tmp) return query(lson(u), lson(v), l, m, k);
    else return query(rson(u), rson(v), m+1, r, k-tmp);
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
        for(int i = 1; i <= n; ++i){
            int tmp = lower_bound(lisan+1, lisan+sz+1, a[i]) - lisan;
            root[i] = root[i-1];
            build(root[i], 1, sz, tmp);
        }
        int l, r, k;
        for(int i = 0; i < m; ++i){
            scanf("%d %d %d", &l, &r, &k);
            int tmp = query(root[l-1], root[r], 1, sz, k);
            printf("%d\n", lisan[tmp]);
        }
    }
}
