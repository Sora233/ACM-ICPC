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
    int n;
    while(scanf("%d",&n)!=EOF){
        int flag=0;
        for(int i=1;i<=n;++i){
            if(n-i==1||n-i==2||n-i==4||n-i==7||n-i==15) {
                    if(flag) printf(" ");
                    printf("%d",i);
                    flag=1;
            }
        }
        printf("\n");
    }
}
