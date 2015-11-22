#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int n;
struct pt{
    double x, y, v;
    int id;
    bool operator < (pt b)const{
        return y < b.y || (y == b.y) && x < b.x;
    }
}dot[N], data[N], all[N];
double dis(pt a, pt b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double cromul(pt a, pt b, pt c){ //ab × ac
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}
int Convex(int n){
    int top = 1;
    sort(data, data+n);
    if(n == 0) return 0;
    dot[0] = data[0];
    if(n == 1) return 1;
    dot[1] = data[1];
    if(n == 2) return 2;
    dot[2] = data[2];

    for(int i = 2; i < n; ++i){
        while(top && cromul(dot[top-1], data[i], dot[top]) > 0) top -= 1;
        dot[++top] = data[i];
    }
    int len = top;
    dot[++top] = data[n-2];
    for(int i = n - 3; i >= 0; --i){
        while(top != len && cromul(dot[top-1], data[i], dot[top]) > 0 ) top -= 1;
        dot[++top] = data[i];
    }
    return top;
}
int main(){
    int ca = 1;
    while(scanf("%d", &n) != EOF && n){
        printf("Case #%d: ", ca++);
        bool flag[N] = {0};
        double mx = 0;
        for(int i = 0; i < n; ++i){
            scanf("%lf %lf %lf", &all[i].x, &all[i].y, &all[i].v);
            all[i].id = i;
            mx = max(mx, all[i].v);
        }
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if(all[i].x==all[j].x && all[i].y==all[j].y && all[i].v==all[j].v){
                    all[j].v = 0;
                    all[i].id = all[j].id = -1;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(all[i].v == mx) data[cnt++] = all[i];
        }
        if(mx){
            int top = Convex(cnt);
            for(int i = 0; i < top; ++i) {
                if(dot[i].id != -1) flag[dot[i].id] = 1;
            }
        }
        for(int i = 0; i < n; ++i) printf("%d", flag[i]);
        putchar('\n');
    }
}
