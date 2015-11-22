#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<functional>
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
#define LL __int64
#define INF 0x7fffffff
#define LLINF 0x7fffffffffffffff
using namespace std;
const int N = 60005;
bool let[N];
struct node{
    int l, r, m, val;
}tree[N<<2];
void build(int c, int l, int r){
    tree[c].l = l, tree[c].r = r;
    if(l == r){
        if(l >= 2) tree[c].val = (let[l-2] == 1 && let[l-1] == 0 && let[l] == 1);
        else tree[c].val = 0;
        return;
    }
    tree[c].m = (l+r)>>1;
    build(c<<1, l, tree[c].m);
    build(c<<1|1, tree[c].m+1, r);
    tree[c].val = tree[c<<1].val + tree[c<<1|1].val;
}
void update(int c, int pos, int val){
    if(tree[c].l == tree[c]. r){
        tree[c].val = val;
        return ;
    }
    if(tree[c].m >= pos) update(c<<1, pos, val);
    else update(c<<1|1, pos, val);
    tree[c].val = tree[c<<1].val + tree[c<<1|1].val;
}
int query(int c, int l, int r){
    if(tree[c].l >= l && tree[c].r <= r){
        return tree[c].val;
    }
    int res = 0;
    if(l <=tree[c].m) res += query(c<<1, l, r);
    if(r > tree[c].m) res += query(c<<1|1, l, r);
    return res;
}
int main(){
    int T, ca = 1, a, b, c;
    char p;
    scanf("%d%*c", &T);
    while( T-- ){
        int n, m;
        scanf("%d %d%*c", &n, &m);
        for(int i = 1; i <= n; ++i){
            p = getchar();
            let[i] = (p=='w');
        }
        printf("Case %d:\n", ca++);
        build(1, 1, n);
        while( m-- ){
            scanf("%d %d%*c", &a, &b);
            if(a == 0){
                scanf("%d%*c", &c);
                c += 1, b += 1;
                if(b+2 > c) puts("0");
            	else printf("%d\n", query(1, b+2, c) );
            }
            else{
            	b += 1;
                scanf("%c%*c", &p);
                c = (p=='w');
                if(let[b] == c) continue;
                let[b] = c;
                if(b >= 3){ // b是最右结点
                    if(let[b-2] == 1 && let[b-1] == 0 && let[b] == 1) update(1, b, 1);
                    else update(1, b, 0);
                }
                if(b >= 2 && b <= n-1){ // b是中间结点
                    if(let[b-1] == 1 && let[b] == 0 && let[b+1] == 1) update(1, b+1, 1);
                    else update(1, b+1, 0);
                }
                if(b<=n-2){
                	if(let[b] == 1 && let[b+1] == 0 &&let[b+2] == 1) update(1, b+2, 1);
               		else update(1, b+2, 0);
            	}
            }
        }
    }
}
