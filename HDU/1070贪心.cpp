#include<iostream>
#include<string>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int main(){
    int T;
    cin>> T;
    while( T-- ){
        int  n, percost = INF, vol = 0;
        string s, ans;
        cin >> n;
        while(n--){
            int cost, p, day = 0;
            cin >> s >> cost >> p;
            if(p < 200) continue;
            day = p / 200;
            if(day > 5) day = 5;
            if( cost/day < percost ||(cost/day == percost && p > vol) ){
                ans = s;
                percost = cost/day;
                vol = p;
            }
        }
        cout<<ans<<endl;
    }
}
