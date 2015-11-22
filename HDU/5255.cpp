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
int main(){
    int T,ca=1;
    scanf("%d",&T);
    while(T--){
        double x;
        scanf("%lf",&x);
        vector<LL>ans;
        int co=0;
        for(int len=1;len<=10;++len){ //长度
            double P=pow(10.0,len-1)+1;
            for(int i=1;i<9;++i) //首位
            {
                for(int j=i+1;j<=9;++j) //末位
                {
                    double solv=P*(j-i)/(x-1);
                    if( fabs((solv- (LL)solv) )<1e-9){
                        ans.pb( (LL) solv);
                        co+=1;
                    }
                }
            }
        }
        printf("Case #%d:\n%d\n%lld",ca++,co,ans[0]);
        for(int i=0;i<ans.size();++i)
            printf(" %lld",ans[i]);
    }
}
