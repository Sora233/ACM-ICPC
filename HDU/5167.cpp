#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<string>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
LL fib[50]={0,1,1};
bool search(LL n,int l){
    if(n==0||n==1) return 1;
    for(int i=l;i>=3;--i){
        if(n%fib[i]==0)  {
               int flag=search(n/fib[i],i);
               if(flag) return 1;
        }
    }
    return 0;
}
int main(){
    for(int i=3;i<50;++i) {
            fib[i]=fib[i-1]+fib[i-2];
    }
    int T;
    scanf("%d",&T);
    while(T--){
        LL n;
        scanf("%lld",&n);
        printf("%s\n",search(n,45)?"Yes":"No");
    }
}
