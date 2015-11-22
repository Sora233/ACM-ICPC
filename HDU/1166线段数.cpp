#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<string>
using namespace std;
const int N=50005;
struct node{
	int l,r,val;
}tree[4*N];
int n;
void build(int s,int l,int r){
	tree[s].l=l,tree[s].r=r;
	if(l==r){
		scanf("%d",&tree[s].val);
		return;
	}
	build(s*2,l,(l+r)>>1);
	build(s*2+1,((l+r)>>1)+1,r);
	tree[s].val=tree[s*2].val+tree[s*2+1].val;
}
void update(int s,int c,int val){
	if(tree[s].r==tree[s].l){
		tree[s].val+=val;
		return;
	}
	if(c<=(tree[s].l+tree[s].r)/2) update(s*2,c,val);
	else update(s*2+1,c,val);
	tree[s].val=tree[s*2].val+tree[s*2+1].val;
}
int query(int c,int ql,int qr){
	if(ql<=tree[c].l&&qr>=tree[c].r) return tree[c].val;
	int res=0;
	if(ql<=(tree[c].l+tree[c].r)>>1) res+=query(c*2,ql,qr);
	if(qr>(tree[c].l+tree[c].r>>1)) res+=query(c*2+1,ql,qr);
	return res;
}
int main(){
	int T,a,b,ca=1;
	string que;
	scanf("%d",&T);
	while(T--){
		printf("Case %d:\n",ca++);
		memset(tree,0,sizeof(tree));
		scanf("%d",&n);
		build(1,1,n);
		while(cin>>que&&que!="End"){
			scanf("%d %d",&a,&b);
			if(que=="Add") update(1,a,b);
			else if(que=="Sub") update(1,a,-b);
			else if(que=="Query") printf("%d\n",query(1,a,b));
		}
	}
}

