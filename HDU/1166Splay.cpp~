#include<bits/stdc++.h>
using namespace std;
const int MN = 50005;
struct SplayTree{
    int size[MN], kid[MN][2], pre[MN], data[MN], root, cnt;
    int num[MN], n, sum[MN];
    void NewNode(int &r, int val, int parent){
        r = ++cnt;
        kid[r][0] = kid[r][1] = 0;
        size[r] = 1;
        data[r] = sum[r] = val;
        pre[r] = parent;
    }
    void push_up(int r){
        sum[r] = sum[kid[r][0]] + sum[kid[r][1]] + data[r];
        size[r] = size[kid[r][1]] + size[kid[r][0]] + 1;
    }
    void Rotate(int x, int f){
        int y = pre[x];
        kid[y][!f] = kid[x][f];
        pre[kid[x][f]] = y;
        pre[x] = pre[y];
        if(pre[x]) kid[pre[y]][kid[pre[y]][1] == y] = x;
        kid[x][f] = y;
        pre[y] = x;
        push_up(y);
    }
    void Splay(int x, int goal){
        while(pre[x] != goal){
            if(pre[pre[x]] == goal) Rotate(x, kid[pre[x]][0] == x);
            else{
                int y = pre[x], z = pre[y];
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
    void RotateTo(int k, int goal){
        int x = root;
        while(size[kid[x][0]] != k){
            if(k < size[ kid[x][0] ]){
                x = kid[x][0];
            }
            else{
                k -= size[kid[x][0]] + 1;
                x = kid[x][1];
            }
        }
        Splay(x, goal);
    }
    void build(int &x, int l, int r, int parent){
        if(l > r) return;
        int m = (l+r) >> 1;
        NewNode(x, num[m], parent);
        if(l < m) build(kid[x][0], l, m-1, x);
        if(r > m) build(kid[x][1], m+1, r, x);
        push_up(x);
    }
    void init(){
        kid[0][0] = kid[0][1] = pre[0] = size[0] = sum[0] = 0;
        root = cnt = 0;
        NewNode(root, -1, 0);
        NewNode(kid[root][1], -1, root);
        size[root] = 2;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", &num[i]);
        build(kid[kid[root][1]][0], 0, n-1, kid[root][1]);
        push_up(kid[root][1]);
        push_up(root);
    }
    void update(int a, int val){
        RotateTo(a, 0);
        data[root] += val;
        sum[root] += val;
    }
    void query(int l, int r){
        RotateTo(l-1, 0);
        RotateTo(r+1, root);
        printf("%d\n", sum[kid[kid[root][1]][0]]);
    }
}spl;
int main(){
    int T, a, b;
    char str[15];
    scanf("%d%*c", &T);
    for(int ca = 1; ca <= T; ++ca){
        printf("Case %d:\n", ca);
        spl.init();
        while( scanf("%s", str) != EOF){
            if(str[0] == 'E') break;
            scanf("%d %d%*c", &a, &b);
            if(str[0] == 'A') spl.update(a, b);
            else if(str[0] == 'S') spl.update(a, -b);
            else if(str[0] == 'Q') spl.query(a, b);
        }
    }
}
