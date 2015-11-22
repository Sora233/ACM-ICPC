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
using namespace std;
int mat[50][50];
bool vis[50] = {0};
int path[50];
int t, d;
void dfs(int now, int lev){
    if( lev == 21 && mat[now][d] ){
        printf("%d: ", t++);
        for(int i = 1; i <= 20; ++i) printf(" %d", path[i]);
        printf(" %d\n", d);
        return;
    }
    for(int i = 1; i <= 20; ++i){
        if( !vis[i] && mat[now][i]){
            vis[i] = 1;
            path[lev] = i;
            dfs(i, lev+1);
            vis[i] = 0;
        }
    }
}
int main(){
    int a, b, c;
    for(int i = 1; i <= 20; ++i){
        scanf("%d %d %d", &a, &b, &c);
        mat[i][a] = mat[i][b] = mat[i][c] = 1;
    }
    while( scanf("%d", &d) != EOF && d ){
        path[1] = d;
        t = 1;
        vis[d] = 1;
        dfs(d, 2);
        vis[d] = 0;
    }
}
