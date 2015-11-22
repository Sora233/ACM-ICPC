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
        int a,b;
        cin>>a>>b;
        if(a%(b+1)==0) cout<<"Rabbit"<<endl;
        else cout<<"Grass"<<endl;
    }
}
