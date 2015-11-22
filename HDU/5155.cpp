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
#define Mod 1000000007
using namespace std;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int k=max(n,m);
        int la=min(n,m);
        int l=n*m-k;
        if(n==1&&m==1){
            printf("1\n");
            continue;
        }
        LL ans=(2*(2*(k-la+1)))*(1<<l)-1;
        printf("%lld\n",ans);
    }
}
