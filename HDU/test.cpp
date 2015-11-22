#include<bits/stdc++.h>
using namespace std;
string cal(string x){
    if(x.length() == 1) return x;
    int sum = 0;
    for(int i = 0; i < x.length(); ++i){
        sum += x[i]-'0';
    };
    char s[1234];
    sprintf(s, "%d", sum);
    return cal(string(s));
}
int main(){
    string a;
    while(cin>>a && a!="0"){
        cout << cal(a) << endl;
    }
}
