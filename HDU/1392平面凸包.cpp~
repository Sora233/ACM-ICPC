#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const double esp = 1e-5;
int n;
bool EQL(double a, double b){
    return fabs(a-b) < esp;
}
struct pt{
    double x, y;
    pt(){}
    pt(double a, double b){ x = a, y = b; }
}dot[N], tree[N];
double dis(pt a, pt b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double cromul(pt a, pt b, pt c){ //ab × ac
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}
bool cmp(pt a, pt b){
    double m = cromul(tree[0], a, b);
    if(m < 0) return 0;
    else if(m == 0) return dis(tree[0], a) <  dis(tree[0], b);
    else return 1;
}
double Convex(){
    int pos = 0;
    for(int i = 1; i < n; ++i){
        if(tree[pos].y > tree[i].y) pos = i;
        else if(EQL(tree[pos].y, tree[i].y) && tree[pos].x > tree[i].x) 
            pos = i;
    }
    if(pos) swap(tree[0], tree[pos]);
    sort(tree+1, tree+n, cmp);
    tree[n] = tree[0];
    for(int i = 0; i < 3; ++i) dot[i] = tree[i];
    int top = 2;
    for(int i = 3; i <= n; ++i){
        while(cromul(dot[top-1], dot[top], tree[i]) < 0) top -= 1;
        dot[++top] = tree[i];
    }
    double ans = 0;
    for(int i = 0; i < top; ++i){
        ans += dis(dot[i], dot[i+1]);
    }
    return ans;
}
int main(){ 
    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; ++i){
            scanf("%lf %lf", &tree[i].x, &tree[i].y);
        }
        if(n == 1){
            puts("0.00");
            continue;
        }
        else if(n == 2){
            printf("%.2f\n", dis(tree[0], tree[1]));
            continue;
        }
        printf("%.2f\n", Convex());
    }
}
