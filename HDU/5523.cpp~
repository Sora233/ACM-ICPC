#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, s, t;
    while(scanf("%d %d %d", &n, &s, &t) != EOF){
        if(n == 1) puts("0");
        else if(s == t) puts("-1");
        else if(s == 1 && t == n || s == n && t == 1) puts("0");
        else if(s == 1 && t != n || s == n && t != 1 ||
                s + 1 == t || t + 1 == s)puts("1");
        else puts("2");
    }
}
