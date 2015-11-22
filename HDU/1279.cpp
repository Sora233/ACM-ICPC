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
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        vector<int>q;
        int n;
        scanf("%d",&n);
        while(n!=1){
            if(n&1) {
                q.pb(n);
                n=n*3+1;
            }
            else n>>=1;
        }
        if(q.empty()){
            puts("No number can be output !");
        }
        else {
            for(int i=0;i<q.size();++i){
                if(!i) printf("%d",q[i]);
                else printf(" %d",q[i]);
            }
            printf("\n");
        }
    }
}
