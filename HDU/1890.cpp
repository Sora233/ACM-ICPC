#include<bits/stdc++.h>
#define lson(r) kid[r][0]
#define rson(r) kid[r][1]
using namespace std;
const int MN = 100005;
int pre[MN], size[MN], kid[MN][2];
int rev[MN];
int root, cnt;
int n;
void NewNode(int &x, int val, int f){
    x = val;
    pre[x] = f;
    lson(x) = rson(x) = 0;
    size[x] = 1;
    rev[x] = 0;
}
void push_down(int x){
    if(rev[x]){
        rev[lson(x)] ^= 1;
        rev[rson(x)] ^= 1;
        swap(lson(x), rson(x));
        rev[x] = 0;
    }
}
void push_up(int x){
    size[x] = size[lson(x)] + size[rson(x)] + 1;
}
void Rotate(int x, int f){
    int y = pre[x];
    push_down(y); push_down(x);
    kid[y][!f] = kid[x][f];
    pre[kid[x][f]] = y;
    if(pre[y]) kid[pre[y]][ rson(pre[y]) == y] = x;
    pre[x] = pre[y];
    pre[y] = x;
    kid[x][f] = y;
    push_up(y);
}
void Splay(int x, int goal){
    push_down(x);
    while(pre[x] != goal){
        if(pre[pre[x]] == goal){
            Rotate(x, lson(pre[x]) == x);
        }
        else{
            int y = pre[x], z = pre[y];
            push_down(z); push_down(y); push_down(x);
            int f = kid[z][0] == y;
            if(kid[y][f] == x){
                Rotate(x, !f);
                Rotate(x, f);
            }
            else{
                Rotate(y, f);
                Rotate(x, f);
            }
        }
    }
    push_up(x);
    if(goal == 0) root = x;
}
int getmax(int x){
    push_down(x);
    while(rson(x)){
        x = rson(x);
        push_down(x);
    }
    return x;
}
void remove(){
    if(lson(root) == 0){
        root = rson(root);
        pre[root] = 0;
    }
    else{
        int m = getmax(lson(root));
        Splay(m, root);
        rson(m) = rson(root);
        pre[rson(root)] = m;
        root = m;
        pre[root] = 0;
        push_up(root);
    }
}
void build(int &x, int l, int r, int f){
    if(l > r) return;
    int m = (l+r) >> 1;
    NewNode(x, m, f);
    build(lson(x), l, m-1, x);
    build(rson(x), m+1, r, x);
    push_up(x);
}
struct node{
    int id, num;
    bool operator<(node a) const{
        return num != a.num? num < a.num : id < a. id;
    }
}a[MN];
void init(){
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i].num);
        a[i].id = i;
    }
    sort(a+1, a+n+1);
    lson(0) = rson(0) = pre[0] = size[0] = rev[0] = 0;
    root = cnt = 0;
    build(root, 1, n, 0);
}
int main(){
    while(scanf("%d", &n) != EOF&&n){
        init();
        for(int i = 1; i < n; ++i){
            Splay(a[i].id, 0);
            rev[lson(root)] ^= 1;
            printf("%d ", i+size[lson(root)]);
            remove();
        }
        printf("%d\n", n);
    }
}
