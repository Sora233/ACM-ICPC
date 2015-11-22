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
const int N=50005;
int ks[N],n;
int lowbit(int x){return x&(-x);}
void update(int pos,int val){
    while(pos<=n){
        ks[pos]+=val;
        pos+=lowbit(pos);
    }
}
int getsum(int p){
    int res=0;
    while(p>0){
        res+=ks[p];
        p-=lowbit(p);
    }
    return res;
}
int main(){
    int T,ca=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",ca++);
        int tmp;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d%*c",&tmp);
            update(i,tmp);
        }
        char s[50];
        while(scanf("%s",s)!=EOF&&s[0]!='E'){
            int i,j;
            scanf("%d %d%*c",&i,&j);
            if(s[0]=='A') update(i,j);
            else if(s[0]=='S') update(i,-j);
            else printf("%d\n",getsum(j)-getsum(i-1));
        }
    }
}
