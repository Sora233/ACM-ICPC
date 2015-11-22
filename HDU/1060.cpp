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
        int n;
        cin>>n;
        LL d=(LL)(n*log10(n));
        int l=(int)pow(10,n*log10(n)-d);
        cout<<l<<endl;
    }
}
