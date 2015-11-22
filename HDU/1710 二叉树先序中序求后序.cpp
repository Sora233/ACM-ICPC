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
struct node{
    int val;
    struct node * lchild, * rchild;
}tree[40005];
int alloc;
int pre[40005], mid[40005];
vector<int>ans;
struct node* build(int prel,int prer,int midl,int midr){
    if(prer - prel < 0) return NULL;
    node *c = &tree[alloc++];
    c->lchild = NULL;
    c->rchild = NULL;
    c->val = pre[prel];
    if( prer == prel ) return c;
    int pos;
    for(pos = midl; pos <= midr; ++pos){
        if(mid[pos] == pre[prel]) break;
    }
    c->lchild = build(prel+1, prel+(pos-midl), midl, pos-1);
    c->rchild = build(prel+(pos-midl)+1, prer, pos+1, midr);
    return c;
}
void printback(node * c){
    if( c == NULL ) return;
    printback(c->rchild);
    printback(c->lchild);
    ans.pb(c->val);
}
int main(){
    int n;
    while( scanf("%d", &n) != EOF ){
        memset(tree, 0, sizeof(tree));
        alloc = 0;
        ans.clear();
        for(int i = 0; i < n; ++i) scanf("%d", &pre[i]);
        for(int i = 0; i < n; ++i) scanf("%d", &mid[i]);
        node *head = build(0, n-1, 0, n-1);
        printback(head);
        printf("%d",ans[0]);
        for(int i = 1; i < ans.size(); ++i)
            printf(" %d", ans[i]);
        puts("");
    }
}
