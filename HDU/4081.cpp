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
const int N = 1005;
struct node{
    int x, y, p;
}ci[N];
struct eg{
    int u, v;
    double dis;
    eg(){}
    eg(int a, int b, double c) { u = a, v = b, dis = c; }
    bool operator < ( eg a ) const {
        return dis < a.dis;
    }
}edg[N*N];
vector<int>pedg;
double dis(int i, int j){
    return sqrt( (ci[i].x - ci[j].x) * (ci[i].x - ci[j].x) + (ci[i].y - ci[j].y) * (ci[i].y - ci[j].y) );
}
int seed[N];
int find(int x) { return seed[x] < 0 ? x : seed[x] = find(seed[x]); }
int join(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return 0;
    seed[b] = a;
    return 1;
}
void MSTEDG(int e){
    memset(seed, -1, sizeof(seed));
    pedg.clear();
    for(int i = 0; i < e; ++i){
        if( join(edg[i].u, edg[i].v) ) pedg.pb(i);
    }
}
double MST(int e){
    double res = 0;
    for(int i = 0; i < e; ++i){
        if(join(edg[i].u, edg[i].v) ) res += edg[i].dis;
    }
    return res;
}
int main(){
    int T;
    scanf("%d", &T);
    while( T-- ){
        int n, x, y, p, ecnt = 0, up = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d %d %d", &ci[i].x, &ci[i].y, &ci[i].p);
        for(int i = 1; i <= n; ++i){
            for(int j = i+1; j <= n; ++j){Ŀ
                edg[ecnt++] = eg(i, j, dis(i, j) );
                up = max(up, ci[i].p + ci[j].p);
            }
        }
        sort(edg, edg + ecnt);
        MSTEDG(ecnt);
        for(int i = 0; i < ecnt; ++i){
            if(ci[edg[i].u].p + ci[edg[i].v].p >= up/2) pedg.pb(i);
        }
        double ans = 0;
        for(int i = 0; i < pedg.size(); ++i){
            memset(seed, -1, sizeof(seed));
            double tmp = ci[edg[pedg[i]].u].p  + ci[edg[pedg[i]].v].p;
            cout<<"u= "<< edg[pedg[i]].u <<", poplu="<<ci[edg[pedg[i]].u].p<<",v="<<edg[pedg[i]].v<<",poplu="<<ci[edg[pedg[i]].v].p<<endl;
            join(edg[i].u, edg[i].v);
            double mst = MST(ecnt);
            cout<<"mst=" <<mst<<", tmp = "<<tmp<<endl;
            ans = max(tmp/mst, ans);
        }
        printf("%.2f\n", ans);
    }
}
