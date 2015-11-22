#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
#include<ctime>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
bool isprime(int x){
    double f=sqrt(x);
    for(int i=2;i<=f;++i){
        if(x%i==0) return 0;
    }
    return 1;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int p,ans=0;
        while(n--){
            scanf("%d",&p);
            if(isprime(p)) ans+=1;
        }
        printf("%d\n",ans);
    }
}
