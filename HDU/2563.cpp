#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<functional>
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
int main(){
    int ans[25]={0,3,7};
    for(int i=3;i<=20;++i) ans[i]=ans[i-2]+2*ans[i-1];
    int T;
    scanf("%d",&T);
    while(T--){
        int a;
        scanf("%d",&a);
        printf("%d\n",ans[a]);
    }
}
