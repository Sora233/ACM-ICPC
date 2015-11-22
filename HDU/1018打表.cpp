#include<bits/stdc++.h>
using namespace std;
int solve(int n){ 
    double sum = 0;
    for(int i = 2; i <= n; ++i) sum += log(i);
    return (int)(sum/log(10))+1;
}
int main(){
    int ans;
    for(int i = 1; i <= 10000; ++i){
        ans += solve(i);
    }
    printf("%d\n", ans);
}
