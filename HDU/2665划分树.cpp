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
const int N=100005;
int n,m;
int tree[20][N];
int sum[20][N];
int sorted[N];
void build(int dep,int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1;
    int same=mid-l+1;
    for(int i=l;i<=r;++i) if(tree[dep][i]<sorted[mid]) same-=1;

    int lpos=l,rpos=mid+1;
    for(int i=l;i<=r;++i){
        if(tree[dep][i]<sorted[mid]) tree[dep+1][lpos++]=tree[dep][i];
        else if(tree[dep][i]==sorted[mid] && same) tree[dep+1][lpos++]=tree[dep][i],same-=1;
        else tree[dep+1][rpos++]=tree[dep][i];
        sum[dep][i]=sum[dep][l-1]+lpos-l;
    }
    build(dep+1,l,mid);
    build(dep+1,mid+1,r);
}
int query(int dep,int l,int r,int ql,int qr,int k){
    if(ql==qr) return tree[dep][ql];
    int mid=(l+r)>>1;
    int cnt = sum [dep][qr] - sum[dep][ql-1];
    if(cnt>=k){
            // l +要查询的区间前被放在左边的个数
        int newl = l +sum[dep][ql-1]-sum[dep][l-1];  //新的左端点
            //newl 加上查询区间会被放在左边的个数
        int newr = newl +cnt -1;
        return query(dep+1,l,mid,newl,newr,k);
    }
    else {
        int newr = qr+sum[dep][r] - sum[dep][qr];
        int newl=newr +cnt - (qr - ql);
        return query(dep+1,mid+1,r,newl,newr,k-cnt);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while( T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i){
            scanf("%d",&tree[0][i]);
            sorted[i]=tree[0][i];
        }
        sort(sorted+1,sorted+1+n);
        build(0,1,n);
        while(m--){
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",query(0,1,n,l,r,k));
        }
    }
}
