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
int s,e,len;
char str[25];
bool vis[1<<16];
int gett(char p[]){
    int res=0,cort=0;
    len=strlen(p);
    for(int i=len-1;i>=0;--i,++cort){
        if(p[i]=='1') res|=(1<<cort);
    }
    e=(1<<len)-1;
    return res;
}
int bfs(int s){
    memset(vis,0,sizeof(vis));
    queue<pii >q;
    vis[s]=1;
    q.push(make_pair(s,0));
    while(!q.empty()){
        for(int i=len-1,cort=0;i>=0;--i){
                int now=q.front().first,t=q.front().second;
                now^=(1<<cort);
                if(cort) now^=(1<<cort-1);
                if(cort!=len-1) now^=(1<<cort+1);
                if(!vis[now]){
                    vis[now]=1;
                    q.push(make_pair(now,t+1));
                    if(now==e) return t+1;
                }
        }
        q.pop();
    }
    return -1;
}
int main(){
    while(scanf("%s",str)!=EOF){
            s=gett(str);
            int tmp=bfs(s);
            if(tmp==-1) puts("NO");
            else printf("%d\n",tmp);
    }
}
