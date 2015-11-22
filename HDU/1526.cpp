#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#define LL long long in
#define INF 0x7fffffff
using namespace std;
map<string, int>mp;
int mat[1005][1005];
int plu, fac, trans, cnt;
int fir[20005], nex[20005];
int U[20005], V[20005], ecnt;
int dis[1005], ef[1005];
queue<int>q;
void add(int a, int b){
    U[ecnt] = a, V[ecnt] = b;
    nex[ecnt] = fir[a];
    fir[a] = ecnt ++;
    U[ecnt] = b, V[ecnt] = a;
    nex[ecnt] = fir[b];
    fir[b] = ecnt++;
}
void push(int s, int t, int u,int &ans){
    int v, p;
    for(int k = fir[u]; k != -1; k = nex[k]){
        v = V[k], p = min(mat[u][v], ef[u]);
        if( p && (u == s || dis[u] == dis[v] + 1)){
            mat[u][v] -= p, mat[v][u] += p;
            ef[u] -= p, ef[v] += p;
            if( v == t) ans += p;
            if( v != s && v!=t ) q.push(v);
        }
    }
}
void relabel(int s, int t, int u){
    if(u != s && u != t && ef[u]){
        dis[u]+=1;
        q.push(u);
    }
}
void push_relabel(int s, int t, int n){
    int ans = 0;
    memset(dis, 0, sizeof(dis));
    dis[s] = n;
    ef[s] = INF, ef[t] = -INF;
    q.push(s);
    int u;
    while(!q.empty()){
        u = q.front(); q.pop();
        push(s, t, u, ans);
        relabel(s, t, u);
    }
    printf("%d\n", fac - ans);
}
int main(){
    int T=0, s = 0, t = 1000;
    char p[50], p1[50];
    scanf("%d", &T);
    while(T--){
        scanf("%d", &plu);
        int tmp, tmp1;
        mp.clear();
        cnt = 1, ecnt = 0;
        memset(fir, -1, sizeof(fir));
        memset(mat, 0, sizeof(mat));
        for(int i = 0; i < plu; ++i){
            scanf("%s", p);
            if( (tmp=mp[p]) == 0) tmp = mp[p] = cnt++;
            if( !mat[s][tmp] ){
                add(s, tmp);
            }
            mat[s][tmp] += 1;
        }
        scanf("%d%*c", &fac);
        for(int i = 0; i < fac; ++i){
            scanf("%s%s", p1, p);
            if( (tmp=mp[p]) == 0) tmp = mp[p] = cnt++;
            if( (tmp1=mp[p1]) == 0) tmp1 = mp[p1] = cnt++;
            mat[tmp1][tmp] += 1;
            mat[tmp][t] += 1;
            add(tmp1, tmp);
            add(tmp, t);
        }
        scanf("%d%*c", &trans);
        for(int i = 0; i < trans; ++i){
            scanf("%s%s", p, p1);
            if( (tmp=mp[p]) == 0) tmp = mp[p] = cnt++;
            if( (tmp1=mp[p1]) == 0 ) tmp1 = mp[p1] = cnt++;
            mat[tmp1][tmp] = INF;
            add(tmp1, tmp);
        }
        push_relabel(s, t, cnt);
        if(T) printf("\n");
    }
}
