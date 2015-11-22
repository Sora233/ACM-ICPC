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
int seed[1005];
int find(int x){return seed[x]<0?x:find(seed[x]);}
int join(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return 0;
    seed[b]=a;
    return 1;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(seed,-1,sizeof(seed));
        int ans=0;
        for(int i=0;i<m;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            a=find(a),b=find(b);
            if(!join(a,b)) ans+=1;
        }
        printf("%d\n",ans);
    }
}
