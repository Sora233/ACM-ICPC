#include<bits/stdc++.h>
using namespace std;
int num[105];
int main(){
    int n, flag;
    while(scanf("%d", &n)!= EOF){
        flag = 0;
        for(int i = 0; i < n; ++i) scanf("%d", &num[i]);
        for(int i = 0; i < n && !flag; ++i){
            for(int j = 0; j < n && !flag; ++j){
                for(int k = 0; k < n && !flag; ++k){
                    if(i == j) break;
                    if(i == k || j == k) continue;
                    if(num[i] == num[j] - num[k]) flag = 1;
                }
            }
        }
        printf("%s\n", flag? "YES" : "NO");
    }
}
