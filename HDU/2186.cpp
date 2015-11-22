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
    cin>>T;
    while(T--){
        int n,ans=0;
        cin>>n;
        int a=n/2;
        int b=(n-a)*2/3;
        int c=n-a-b;
        while(a>=10) a-=10,ans+=1;
        if(a) ans+=1;
        while(b>=10) b-=10,ans+=1;
        if(b) ans+=1;
        while(c>=10) c-=10,ans+=1;
        if(c) ans+=1;
        cout<<ans<<endl;
    }
}
