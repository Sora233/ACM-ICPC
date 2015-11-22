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
const int N=6006;
int father[N],root,n;
vector<int>son[N]; //����i�Ķ���
bool vis[N];
int dp[N][2]; // 1��ʾ�� 2��ʾ���� ���� ��i��j����˾ dp[i][1]+=dp[j][0] iȥ��j����ȥ
void TreeDP(int now){                  //          dp[i][0]+=max(dp[j][1],dp[j][0]) ��i��ȥ��ʱ���ȡjȥ��ȥ������ֵ
    vis[now]=1;
    for(int j=0;j<son[now].size();++j){
        int i=son[now][j];
        if(!vis[i]){
            TreeDP(i);
            dp[now][1]+=dp[i][0];
            dp[now][0]+=max(dp[i][1],dp[i][0]);
        }
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        memset(father,0,sizeof(father));
        for(int i=1;i<=n;++i) {
                scanf("%d",&dp[i][1]);
                son[i].clear();
        }
        root=0;
        bool first=1;
        int f,s;
        while(scanf("%d%d",&s,&f)!=EOF&&(f|s)){
            if(first||root==s) root=f,first=0;
            father[s]=f;
            son[f].pb(s);
        }
        while(father[root]) root=father[root];
        TreeDP(root);
        printf("%d\n",max(dp[root][1],dp[root][0]));
    }
}
