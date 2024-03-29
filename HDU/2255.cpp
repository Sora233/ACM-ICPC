#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int N = 305;
int n, ecnt;
struct eg{
    int u, v, cap, cost;
    eg(){}
    eg(int a, int b, int c, int d){ u = a, v = b, cap = c, cost = d; }
}edg[N*N*10];
int fir[N*2], nex[N*N*10];
int pre[N*2], dis[N*2];
void add(int a, int b, int c, int v){
    edg[ecnt] = eg(a, b, c, v);
    nex[ecnt] = fir[a], fir[a] = ecnt++;
    edg[ecnt] = eg(b, a, 0, -v);
    nex[ecnt] = fir[b], fir[b] = ecnt++;
}
int s, t;
bool vis[N<<1];
int flow[N*2];
int q[N*20], top, tail;
int spfa(){
    for(int i = 0; i <= t; ++i) vis[i] = 0, dis[i] = 0x7fffffff;
    memset(pre, -1, sizeof(pre));
    top = tail = 0;
    q[tail++] = s, dis[s] = 0, flow[s] = 0x7fffffff, vis[s] = 1;
    while( top < tail ){
        int u = q[top++];
        vis[u] = 0;
        for(int k = fir[u]; k != -1; k = nex[k]){
            int v = edg[k].v;
            if( edg[k].cap && dis[u] + edg[k].cost < dis[v] ){
                dis[v] = dis[u] + edg[k].cost;
                pre[v] = k;
                flow[v] = min(flow[u], edg[k].cap);
                if( !vis[v] ){
                    q[tail++] = v;
                    vis[v] = 1;
                }
            }
        }
    }
    if(pre[t] == -1) return -1;
    else return flow[t];
}
int mincostEK(){
    int res = 0, minflow;
    while( (minflow = spfa()) != -1 ){
        for(int k = pre[t]; k != -1; k = pre[edg[k].u]){
            edg[k].cap -= minflow;
            edg[k^1].cap += minflow;
        }
        res += dis[t] * minflow;
    }
    return res;
}
int main(){
    int a;
    while( scanf("%d", &n) != EOF ){
        s = 0, t = n*2+1;
        memset(fir, -1, sizeof(fir));
        for(int i = 1; i <= n; ++i){
            add(s, i, 1, 0);
            for(int j = 1; j <= n; ++j){
                scanf("%d", &a);
                add(i, n+j, 1, -a);
         //       add(n+j, i, 1, -a);
            }
            add(i+n, t, 1, 0);
        }
        printf("%d\n", -mincostEK());
    }
}
