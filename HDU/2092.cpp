#include <stdio.h>
#include <math.h>
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),(n!=0)||(m!=0)){
        double x=(n+sqrt(n*n-4*m))/2;
        printf(((int) x==x)?"Yes\n":"No\n");
    }
    return 0;
}
