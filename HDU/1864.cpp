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
int item[35];
int cort=0;
int dp[1000000];
int main(){
    double q,tmp;
    int n;
    while(scanf("%lf%d",&q,&n)!=EOF&&n){
        cort=1;
        for(int i=1;i<=n;++i){
            int k,flag=1;
            double tot=0,a=0,b=0,c=0;
            char s;
            scanf("%d%*c",&k);
            while(k--){
                scanf("%c:%lf%*c",&s,&tmp);
                switch(s){
                    case 'A':a+=tmp;break;
                    case 'B':b+=tmp;break;
                    case 'C':c+=tmp;break;
                    default: flag=0;
                }
            }
            if(flag&&(a+b+c)<=1000&&a<=600&&b<=600&&c<=600) item[cort++]=(int)((a+b+c)*100);
        }
        memset(dp,0,sizeof(dp));
        int up=(int)(q*100);
        for(int i=1;i<cort;++i){
            for(int j=up;j>=item[i];--j){
                dp[j]=max(dp[j],dp[j-item[i]]+item[i]);
            }
        }
        printf("%.2f\n",dp[up]*1.0/100);
    }
}
