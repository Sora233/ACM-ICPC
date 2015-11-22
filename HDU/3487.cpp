#include<bits/stdc++.h>
#define lson(x) kid[x][0]
#define rson(x) kid[x][1]
using namespace std;
const int N = 300005;
int pre[N], size[N], kid[N][2], data[N];
int rev[N];
int root, cnt;
int n, q;
void NewNode(int &x, int val, int f){
    x = ++cnt;
    data[x] = val;
    pre[x] = f;
    size[x] = 1;
    lson(x) = rson(x) = 0;
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
void build(int &x, int l, int r, int f){
    if(l > r) return;
    int m = (l+r) >> 1;
    NewNode(x, m, f);
    build(lson(x), l, m-1, x);
    build(rson(x), m+1, r, x);
    push_up(x);
}
void init(){
    root = cnt = 0;
    pre[0] = lson(0) = rson(0) = size[0] = data[0] = rev[0] = 0;
    NewNode(root, -1, 0);
    NewNode(rson(root), -1, root);
    size[root] = 2;
    build(lson(rson(root)), 1, n, rson(root));
    push_up(rson(root));
    push_up(root);
}
void Rotate(int x, int f){
    int y = pre[x];
    push_down(y); push_down(x);
    kid[y][!f] = kid[x][f];
    pre[kid[x][f]] = y;
    pre[x] = pre[y];
    if(pre[y]) kid[pre[y]][ kid[pre[y]][1] == y ] = x;
    pre[y] = x;
    kid[x][f] = y;
    push_up(y);
}
void Splay(int x, int goal){
    push_down(x);
    while(pre[x] != goal){
        Rotate(x, lson(pre[x]) == x);
    }
    push_up(x);
    if(goal == 0) root = x;
}
void RotateTo(int k, int goal){
    int x = root;
    push_down(x);
    while(size[lson(x)] != k){
        if(k < size[lson(x)]) x = lson(x);
        else {
            k -= size[lson(x)] + 1;
            x = rson(x);
        }
        push_down(x);
    }
    Splay(x, goal);
}
void reverse(int l, int r){
    RotateTo(l-1, 0);
    RotateTo(r+1, root);
    rev[lson(rson(root))] ^= 1;
}
int findmin(int r){
    push_down(r);
    while(lson(r)){
        r = lson(r);
        push_down(r);
    }
    return r;
}
void cut(int a, int b){
    int c;
    scanf("%d%*c", &c);

    RotateTo(a-1, 0);
    RotateTo(b+1, root);

    int tmp = lson(rson(root));
    lson(rson(root)) = 0;
    push_up(rson(root));
    push_up(root);

    RotateTo(c, 0);
    Splay(findmin(rson(root)), root);

    lson(rson(root)) = tmp;
    pre[lson(rson(root))] = rson(root);
    push_up(rson(root));
    push_up(root);
}
int flag;
void inorder(int r){
    if(!r) return;
    push_down(r);
    inorder(lson(r));
    if(r > 2 && r <= n + 2){
        if(flag) putchar(' ');
        else flag = 1;
        printf("%d", data[r]);
    }
    inorder(rson(r));
}
int main(){
    char s[10];
    int a, b;
    while(scanf("%d %d%*c", &n, &q) != EOF){
        if(n < 0 || q < 0) break;
        init();
        while(q--){
            scanf("%s %d %d%*c", s, &a, &b);
            if(s[0] == 'C') cut(a, b);
            else if(s[0] == 'F') reverse(a, b);
        }
        flag = 0;
        inorder(root);
        puts("");
    }
}
