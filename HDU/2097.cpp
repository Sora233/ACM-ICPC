#include<bits/stdc++.h>
using namespace std;
int trans(int x, int k){
    int res = 0;
    while(x){
        res += x%k;
        x /= k;
    }
    return res;
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF && n){
        if(trans(n, 10) == trans(n, 12) && trans(n, 12) == trans(n, 16)){
            printf("%d is a Sky Number.\n", n);
        }
        else{
            printf("%d is not a Sky Number.\n", n);
        }
    }
}
