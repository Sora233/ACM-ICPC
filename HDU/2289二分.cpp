#include<bits/stdc++.h>
#define PI acos(-1.0)
using namespace std;
const double ESP = 1e-10;
double r, R, H, V;
double cal(double hei){
    double l = hei/H*(R-r) + r;
    return PI/3*hei*(l*l+r*r+l*r);

}
double erfen(double l, double r){
    double m;
    while(r - l > ESP){
        m = (l+r)/2;
        double tmp = cal(m);
        if(tmp > V) r = m;
        else l = m;
    }
    return l;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%lf %lf %lf %lf", &r, &R, &H, &V);
        printf("%.6f\n", erfen(0, H));
    }
}
