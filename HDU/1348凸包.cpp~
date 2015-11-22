#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
const double esp = 1e-6;
const int N = 1005;
int n;
bool EQL(double a, double b){
    return fabs(a-b) < esp;
}
struct pt{
    double x, y;
    pt(){}
    pt(double a, double b){ x = a, y = b; }
}dot[N], data[N];
double dis(pt a, pt b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double cromul(pt a, pt b, pt c){ //ab × ac
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}
bool cmp(pt a, pt b){
    double m = cromul(data[0], a, b);
    if(m < 0) return 0;
    else if(m == 0) return dis(data[0], a) <  dis(data[0], b);
    else return 1;
}
double Convex(){
    int pos = 0;
    for(int i = 1; i < n; ++i){
        if(data[pos].y > data[i].y) pos = i;
        else if(EQL(data[pos].y, data[i].y) && data[pos].x > data[i].x) 
            pos = i;
    }
    if(pos) swap(data[0], data[pos]);
    sort(data+1, data+n, cmp);
    data[n] = data[0];
    for(int i = 0; i < 3; ++i) dot[i] = data[i];
    int top = 2;
    for(int i = 3; i <= n; ++i){
        while(cromul(dot[top-1], dot[top], data[i]) < 0) top -= 1;
        dot[++top] = data[i];
    }
    double ans = 0;
    for(int i = 0; i < top; ++i){
        ans += dis(dot[i], dot[i+1]);
    }
    return ans;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int l;
        scanf("%d %d", &n, &l);
        for(int i = 0; i < n; ++i){
            scanf("%lf %lf", &data[i].x, &data[i].y);
        }
        printf("%.0f\n", Convex() + PI*l*2);
        if(T) putchar('\n');
    }
}
