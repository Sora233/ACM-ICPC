#include<bits/stdc++.h>
#define ll long long int
using namespace std;
set<ll>num;
void dfs(ll x){
    if(x == 0 || num.count(x)) return;
    num.insert(x);
    if((x-1)%2 == 0) dfs((x-1)/2);
    else{
        dfs((x-1)/2);
        dfs((x-1)/2+1);
    }
}
int main(){
    ll n;
    while(scanf("%lld", &n) != EOF){
        num.clear();
        dfs(n);
        printf("%lld\n", num.size());
    }
}
