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
#define ll I64d 
using namespace std;
LL num[10005];
int main(){
    int T,ca=1;
    scanf("%d",&T);
    while(T--){
    	printf("Case #%d:\n",ca++);
        LL n,m,k,flag=0;
        scanf("%lld%lld%lld",&n,&m,&k);
        for(int i=0;i<n;++i) scanf("%lld",&num[i]);
        sort(num,num+n);
        if(m<num[0]){
            puts("madan!");
            continue;
        }
        else if(m>=num[n-1]){
            puts("why am I so diao?");
            continue;
        }
        int s=lower_bound(num,num+n,m)-num;
        if(num[s]!=m) s-=1;
        LL now=num[s],gain=k;
        for(int i=s;i<n&&!flag;++i)
        {
            if(now==num[i]){
            	if(gain<0) gain=0;
                if(now+gain<num[i+1]) break;
                int p=lower_bound(num,num+n,now+gain)-num;
                if(num[p]!=now+gain) p-=1;
                now=num[p],gain-=1;
                if(p==n-1) flag=1;
            }
			if(now>num[n-1]) flag=1;
        }
        printf("%s\n",flag?"why am I so diao?":"madan!");
    }
}
