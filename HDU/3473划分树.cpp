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
#define lld I64d
#define qseed 0,1,n
using namespace std;
int n,m;
LL tree[20][100005];
LL sorted[100005];
int sum[20][100005];
LL ts[100005],lsum[20][100005];
void build(int dep,int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1;
    int same=mid-l+1;
    for(int i=l;i<=r;++i) if(tree[dep][i]<sorted[mid]) same-=1;
    lsum[dep][0]=0;
    int lpos=l,rpos=mid+1;
    for(int i=l;i<=r;++i){
        lsum[dep][i]=lsum[dep][i-1];
        if(tree[dep][i]<sorted[mid]) {
                tree[dep+1][lpos++]=tree[dep][i];
                lsum[dep][i]+=tree[dep][i];
        }
        else if(tree[dep][i]==sorted[mid] && same) {
                tree[dep+1][lpos++]=tree[dep][i],same-=1;
                lsum[dep][i]+=tree[dep][i];
        }
        else tree[dep+1][rpos++]=tree[dep][i];
        sum[dep][i]=sum[dep][l-1]+lpos-l;
    }
    build(dep+1,l,mid);
    build(dep+1,mid+1,r);
}
LL query(int dep,int l,int r,int ql,int qr,int k){
    if(ql==qr) return tree[dep][ql];
    int mid=(l+r)>>1;
    int cnt=sum[dep][qr] - sum[dep][ql-1];
    if(cnt>=k){
        int newl=l + sum[dep][ql-1]-sum[dep][l-1];
        int newr=newl+cnt-1;
        return query(dep+1,l,mid,newl,newr,k);
    }
    else {
        int newr=qr + sum[dep][r] - sum[dep][qr];
        int newl=newr+cnt- (qr-ql);
        return query(dep+1,mid+1,r,newl,newr,k-cnt);
    }
}
void solve(int l,int r){
    int k=(r-l)/2+1;
    int midval=query(qseed,l,r,k);
}
int main(){
    int T,ca=1;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d:\n",ca++);
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%lld",&tree[0][i]);
            sorted[i]=tree[0][i];
            ts[i]=ts[i-1]+tree[0][i];
        }
        sort(sorted+1,sorted+1+n);
        build(0,1,n);
        scanf("%d",&m);
        while(m--){
            int l,r;
            scanf("%d%d",&l,&r);
            if(l==r) printf("0\n");
            else solve(l+1,r+1);
        }
        printf("\n");
    }
}
