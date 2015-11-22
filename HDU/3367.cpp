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
#define LL __int64
#define INF 0x7fffffff
#define LLINF 0x7fffffffffffffff
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 10005;
const int M = 100005;
int seed[N];
int find(int x){ return seed[x] < 0? x : seed[x] = find(seed[x]); }
int join(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return 0;
    seed[b] = a;
    return 1;
}
struct eg{
    int u, v, w;
    bool operator < (eg a)const {
        return w > a.w;
    }
}edg[M];
int main(){
    int n, m, a, b, c;
    while( scanf("%d %d", &n, &m) != EOF ){
        memset(seed, -1, sizeof(seed));
        for(int i = 0; i < m; ++i) scanf("%d %d %d", &edg[i].u, &edg[i].v, &edg[i].w);
        sort(edg, edg+m);
        int ans = 0;
        for(int i = 0; i < m; ++i){
            if( join(edg[i].u, edg[i].v)) ans += edg[i].w;
        }
        printf("%d\n", ans);
    }
}
