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
#define INF 0x7fffffff
#define LLINF 0x7fffffffffffffff
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int num[105];
int main(){
    int n, ca = 0;
    while( cin >> n && n ){
        if( !ca ) ca = 1;
        else cout<<endl;
        int ans = 0, sum = 0;
        for(int i = 0; i < n; ++i){
            cin >> num[i];
            sum += num[i];
        }
        sum /= n;
        for(int i = 0; i < n; ++i){
            if(num[i] > sum)ans += num[i] - sum;
        }
        cout << ans << endl;
    }
}
