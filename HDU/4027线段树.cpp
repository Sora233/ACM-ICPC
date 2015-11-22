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
#define LL __int64
#define lson l,l+r>>1
#define rson l+r>>1|1,r
#define lld I64d
using namespace std;
struct node{
    int l,r,m,lazy;
    LL val;
}tree[400005];
void pushup(int c){
    tree[c].val=tree[c<<1].val+tree[c<<1|1].val;
    if(tree[c].val<=tree[c].r-tree[c].l+1) tree[c].lazy=1;
}
void build(int c,int l,int r){
    tree[c].l=l,tree[c].r=r,tree[c].lazy=0;
    if(l==r){
        scanf("%lld",&tree[c].val);
        return;
    }
    tree[c].m=(l+r)>>1;
    build(c<<1,l,tree[c].m);
    build(c<<1|1,tree[c].m+1,r);
    pushup(c);
}
void change(int c,int ql,int qr){
    if(tree[c].l>=ql&&tree[c].r<=qr&&tree[c].lazy) return;
    if(tree[c].l==tree[c].r){
        tree[c].val=(LL)(sqrt(tree[c].val));
        return;
    }
    if(ql<=tree[c].m) change(c<<1,ql,qr);
    if(qr>tree[c].m)change(c<<1|1,ql,qr);
    pushup(c);
}
LL query(int c,int ql,int qr){
    if(tree[c].l>=ql&&tree[c].r<=qr){
        return tree[c].val;
    }
    LL res=0;
    if(ql<=tree[c].m) res+=query(c<<1,ql,qr);
    if(qr>tree[c].m) res+=query(c<<1|1,ql,qr);
    return res;
}
int main(){
    int n,ca=1;
    while(scanf("%d",&n)!=EOF){
        printf("Case #%d:\n",ca++);
        build(1,1,n);
        int q;
        scanf("%d",&q);
        while(q--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(b>c) swap(b,c);
            if(a==0){
                change(1,b,c);
            }
            else {
                printf("%lld\n",query(1,b,c));
            }
        }
        printf("\n");
    }
}
