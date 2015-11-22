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
int sorted[N];
int sum[20][N];
void build(int dep,int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1;
    int same=mid-l+1;
    for(int i=l;i<=r;++i) if(tree[dep][i]<sorted[mid]) same-=1;
    int lpos=l,rpos=mid+1;
    for(int i=l;i<=r;++i){
        int &s= tree[dep][i];
        if(s<sorted[mid]) tree[dep+1][lpos++]=s;
        else if(s==sorted[mid] && same) tree[dep+1][lpos++]=s,same-=1;
        else tree[dep+1][rpos++]=s;
        sum[dep][i]=sum[dep][l-1]+lpos-l;
    }
    build(dep+1,l,mid);
    build(dep+1,mid+1,r);
}
int query(int dep,int l,int r,int ql,int qr,int k){
    if(ql==qr) return tree[dep][qr];
    int mid = (l+r)>>1;
    int cnt = sum[dep][qr] - sum[dep][ql-1]; // ql到qr这一段 也就是当前处理到的询问的子区间段分在左边的个数
    if(cnt>=k){ //第k+x大在左边 第k大显然在左边
        int newl=l +sum[dep][ql-1]-sum[dep][l-1];
        int newr=newl+cnt-1;
        return query(dep+1,l,mid,newl,newr,k);
    }
    else {
        int newr=qr+sum[dep][r] - sum[dep][qr];
        int newl=newr+cnt-(qr-ql);
        return query(dep+1,mid+1,r,newl,newr,k-cnt);
    }
}
int solve(int ql,int qr,int k){
    int ans=0;
    int l=1,r=qr-ql+1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        int tmp=query(0,1,n,ql,qr,mid);
        if(tmp<=k){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
int main(){
    int T,ca=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&tree[0][i]);
            sorted[i]=tree[0][i];
        }
        sort(sorted+1,sorted+1+n);
        build(0,1,n);
        printf("Case %d:\n",ca++);
        while(m--){
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",solve(l+1,r+1,k));
        }
    }
}
