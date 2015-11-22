#include<bits/stdc++.h>
using namespace std;
const int MN = 200015;
const int MQ = 5005;
struct SPLAY{
    int pre[MN], kid[MN][2], data[MN], size[MN];
    int mx[MN], num[MN];
    int root, cnt;
    int n, q;
    void push_up(int x){
        mx[x] = max(data[x], max(mx[kid[x][0]], mx[kid[x][1]]));
        size[x] = size[kid[x][0]] + size[kid[x][1]] + 1;
    }
    void NewNode(int &x, int val, int parent){
        x = ++cnt;
        size[x] = 1;
        kid[x][0] = kid[x][1] = 0;
        pre[x] = parent;
        data[x] = mx[x] = val;
    }
    void Rotate(int r, int f){ //0左旋 1右旋
        int y = pre[r];
        kid[y][!f] = kid[r][f];
        pre[kid[r][f]] = y;

        if(pre[y]) kid[pre[y]][ kid[pre[y]][1] == y] = r;
        pre[r] = pre[y];

        pre[y] = r;
        kid[r][f] = y;
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
    void RotateTo(int k, int goal){
        int x = root;
        while(size[kid[x][0]] != k){
            if(k < size[kid[x][0]]) x = kid[x][0];
            else{
                k -= size[kid[x][0]] +1;
                x = kid[x][1];
            }
        }
        Splay(x, goal);
    }
    void build(int &x, int l, int r, int parent){
        if(l > r) return;
        int mid = (l+r) >> 1;
        NewNode(x, num[mid], parent);
        build(kid[x][0], l, mid-1, x);
        build(kid[x][1], mid+1, r, x);
        push_up(x);
    }
    void init(){
        root = cnt = 0;
        kid[0][0] = kid[0][1] = size[0] = mx[0] = pre[0] = 0;
        NewNode(root, -1, 0);
        NewNode(kid[root][1], -1, root);
        size[root] = 2;
        for(int i = 0; i < n; ++i) scanf("%d%*c", &num[i]);
        build(kid[kid[root][1]][0], 0, n-1, kid[root][1]);
        push_up(kid[root][1]);
        push_up(root);
    }
    void update(int a, int val){
        RotateTo(a, 0);
        data[root] = val;
        mx[root] = max(val, max(mx[kid[root][0]], mx[kid[root][1]]));
    }
    void query(int l, int r){
        RotateTo(l-1, 0);
        RotateTo(r+1, root);
        printf("%d\n", mx[kid[kid[root][1]][0]]);
    }
}spl;
int main(){
    char s;
    int a, b;
    while( scanf("%d %d%*c", &spl.n, &spl.q) != EOF ){
        spl.init();
        while(spl.q--){
            scanf("%c %d %d%*c", &s, &a, &b);
            if(s == 'Q') spl.query(a, b);
            else if(s == 'U') spl.update(a, b);
        }
    }
}
