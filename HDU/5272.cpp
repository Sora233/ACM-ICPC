#include<iostream>
#include<algorithm>
#define LL long long int
using namespace std;
int main(){
    int T;
    cin >> T;
    while( T-- ){
        LL n;
        cin >> n;
        int ans = 0, flag = 0;
        for(int i = 62;i >= 0; --i){
            if( (1ll<<i) & n ){
                if( flag == 0 ) flag = 1, ans += 1;
            }
            else flag = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
