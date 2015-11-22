#include<bits/stdc++.h>
#define lson(x) (kid[x][0])
#define rson(x) (kid[x][1])
const int MN = 255555;
using namespace std;
struct SplayTree{
    int pre[MN], size[MN], kid[MN][2], data[MN];
    int mx[MN];
    int root, cnt;
    int h, w, q;
    void push_up(int r){
        size[r] = size[lson(r)] + size[rson(r)] + 1;
        mx[r] = max(data[r], max(mx[lson(r)], mx[rson(r)]));
    }
    void NewNode(int &r, int val, int parent){
        r = ++cnt;
        pre[r] = parent;
        size[r] = 1;
        data[r] = mx[r] = val;
        lson(r) = rson(r) = 0;
    }
    void Rotate(int x, int f){
        int y = pre[x];
        kid[y][!f] = kid[x][f];
        pre[kid[x][f]] = y;

        if(pre[y]) kid[pre[y]][ kid[pre[y]][1] == y] = x;
        pre[x]  = pre[y];

        pre[y] = x;
        kid[x][f] = y;
        push_up(y);
    }
    void Splay(int r, int goal){
        while(pre[r] != goal){
            if(pre[pre[r]] == goal){
                Rotate(r, kid[pre[r]][0] == r);
            }
            else{
                int y = pre[r], z = pre[y];
                int f = kid[z][0] == y;
                if(kid[y][f] == r){
                    Rotate(r, !f);
                    Rotate(r, f);
                }
                else{
                    Rotate(y, f);
                    Rotate(r, f);
                }
            }
        }
        push_up(r);
        if(goal == 0) root = r;
    }
    void RotateTo(int val, int goal){
        int x = root;
        while(1){
            if(mx[kid[x][0]] >= val) x = kid[x][0];
            else if(mx[kid[x][1]] >= val) x = kid[x][1];
            else break;
        }
        Splay(x, goal);
    }
    void build(int &x, int l, int r, int parent){
        if(l > r) return;
        int mid = (l+r) >> 1;
        NewNode(x, w, parent);
        if(l < mid) build(kid[x][0], l, mid-1, x);
        if(r > mid) build(kid[x][1], mid+1, r, x);
        push_up(x);
    }
    void init(){
        root = cnt = 0;
        kid[0][0] = kid[0][1] = size[0] = data[0] = mx[0] = pre[0] = 0;
        NewNode(root, -1, 0);
        NewNode(rson(root), -1, root);
        build(lson(rson(root)), 0, h, rson(root));
        push_up(rson(root));
        push_up(root);
    }
    void query(){
        int val;
        scanf("%d", &val);
        if(mx[root] < val) puts("-1");
        else{
            RotateTo(val, 0);
            printf("%d\n", root-1);
            data[root] -= val;
            push_up(root);
        }
    }
}spl;
int main(){
    while( scanf("%d %d %d", &spl.h, &spl.w, &spl.q) != EOF){
        spl.init();
        while(spl.q--) spl.query();
    }
}
