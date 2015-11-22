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
int n, m;
int u[10005],v[10005],w[10005];
int fir[20005],nex[20005],cnt;
void add(int a, int b, int c){
    u[cnt] = a, v[cnt] = b, w[cnt] = c;
    nex[cnt] = fir[a];
    fir[a] = cnt++;
}
int spfa(int s){
    bool vis[105]={0};
    int dis[105];
    for(int i = 0; i < 105; ++i) dis[i]=0x7fffffff;
    queue<int>q;
    q.push(s); vis[s] = 1; dis[s] = 0;
    while(!q.empty()){
        int a = q.front(); q.pop(); vis[a]=0;
        int b = fir[a];
        while(b != -1){
            if(dis[v[b]] > dis[a] + w[b]){
                dis[v[b]] = dis[a] + w[b];
                if(!vis[v[b]]){
                    q.push(v[b]);
                    vis[v[b]] = 1;
                }
            }
            b = nex[b];
        }
    }
    return dis[n];
}
int main(){
    int a,b,c;
    while( scanf("%d%d", &n, &m) != EOF &&(n+m) ){
        cnt=1;
        memset(fir,-1,sizeof(fir));
        for(int i = 1; i <= m; ++i){
            scanf("%d%d%d", &a, &b, &c);
            add(a,b,c);
            add(b,a,c);
        }
        printf("%d\n", spfa(1));
    }
}
