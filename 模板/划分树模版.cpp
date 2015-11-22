int tree[20][N];
int sorted[N];
int sum[20][N];
void build(int dep,int l,int r){ //建树时 build(0, 1, n)
    if(l==r) return;
    int mid=(l+r)>>1;
    int same=mid-l+1;
    for(int i=l;i<=r;++i) if(tree[dep][i]<sorted[mid]) same-=1;
    int lpos=l,rpos=mid+1;
    for(int i=l;i<=r;++i){
        if(tree[dep][i]<sorted[mid]) {
                tree[dep+1][lpos++]=tree[dep][i];
        }
        else if(tree[dep][i]==sorted[mid] && same) {
                tree[dep+1][lpos++]=tree[dep][i],same-=1;
        }
        else tree[dep+1][rpos++]=tree[dep][i];
        sum[dep][i]=sum[dep][l-1]+lpos-l;
    }
    build(dep+1,l,mid);
    build(dep+1,mid+1,r);
}
//查询时query(0, 1, n, L, R, K); LR为区间 K为第几大
//返回原数列的第K大
int query(int dep,int l,int r,int ql,int qr,int k){
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
