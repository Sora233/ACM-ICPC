//请用G++ 
#include<cstdio>
#include<cmath> 
#define LL __int64
#define lld I64d
using namespace std;
const int MN=100005;
LL fib[100]={1,1,2};
struct node{
    int l,r,m;
	bool lazy; //lazy表示当前结点的区间是否全部在进行过3操作之后没有1操作 
    LL val;
}tree[MN<<2];
int n,m;
void cfib(LL &val){ //二分 
    int l=0,r=90,mid;
    int half,len=91;
    while(len){
        half=len>>1;
        mid=l+half;
        if(fib[mid]<val){
            l=mid+1;
            len-=half-1;
        }
        else len=half;
    }
    if(fib[l]==val) val=fib[l];
    else if(fib[l+1]==val) val=fib[l+1];
    else if(fib[l-1]==val) val=fib[l-1];
    else {
        if(fib[l]>val&&fib[l-1]<val){
        	if(abs(fib[l]-val)<abs(fib[l-1]-val)) val=fib[l];
        	else val=fib[l-1];
        }
        else if(fib[l]<val&&fib[l+1]>val){
        	if(abs(fib[l+1]-val)<abs(fib[l]-val)) val=fib[l+1];
        	else val=fib[l];
        }
    }
}
void build(int c,int l,int r){
    tree[c].l=l,tree[c].r=r,tree[c].lazy=0,tree[c].val=0;
    if(l==r) return;
    tree[c].m=(l+r)>>1;
    build(c<<1,l,tree[c].m);
    build(c<<1|1,tree[c].m+1,r);
}
void update(int c,int pos,int val){
    tree[c].lazy=0; //抹去更新路径的lazy 
    if(tree[c].l==tree[c].r){
        tree[c].val+=val;
        return;
    }
    if(pos<=tree[c].m) update(c<<1,pos,val);
    else update(c<<1|1,pos,val);
    tree[c].val=tree[c<<1].val+tree[c<<1|1].val;
    tree[c].lazy=tree[c<<1].lazy&tree[c<<1|1].lazy;
}
void fibdown(int c){
    if(tree[c].lazy) return; //lazy标记过，当前结点的数已经是斐波数了 
    tree[c].lazy=1; // 打上lazy 
    if(tree[c].l==tree[c].r){
        if(!tree[c].val) tree[c].val=1;
        else cfib(tree[c].val);
        return;
    }
    fibdown(c<<1);
    fibdown(c<<1|1);
    tree[c].val=tree[c<<1].val+tree[c<<1|1].val;
}
void FIB(int c,int ql,int qr){
    if(tree[c].lazy) return;
    if(tree[c].l>=ql&&tree[c].r<=qr){
        fibdown(c); //这棵子树被完全覆盖，用fibdown函数更新这棵子树的叶子节点 
        return;
    }
    if(ql<=tree[c].m) FIB(c<<1,ql,qr);
    if(qr>tree[c].m) FIB(c<<1|1,ql,qr);
    tree[c].val=tree[c<<1].val+tree[c<<1|1].val;
    tree[c].lazy=tree[c<<1].lazy&tree[c<<1|1].lazy; //当前结点的lazy右左右儿子的lazy决定 
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
    int a,b,c;
    for(int i=3;i<100;++i) fib[i]=fib[i-1]+fib[i-2];
    while(scanf("%d %d",&n,&m)!=EOF){
        build(1,1,n);
        while(m--){
            scanf("%d %d %d",&a,&b,&c);
            if(a==1) update(1,b,c);
            else if(a==2) printf("%lld\n",query(1,b,c));
            else FIB(1,b,c); 
        }
    }
}
