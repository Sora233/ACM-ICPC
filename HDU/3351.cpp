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
    char tmp;
    int ca=1;
    while(scanf("%c",&tmp)!=EOF){
        stack<char>s;
        char first=tmp;
        if(tmp=='-') return 0;
        if(tmp=='{'||tmp=='}') s.push(tmp);
        while(scanf("%c",&tmp)!=EOF&&tmp!='\n'){
            if(tmp=='{'||tmp=='}') {
                if(!s.empty()&&s.top()=='{'&&tmp=='}') s.pop();
                else s.push(tmp);
            }
        }
        int len=s.size(),cort=1,l=0,r=0;
        while(!s.empty()){
            if(s.top()=='{') l+=1;
            if(s.top()=='}') r+=1;
            s.pop();
        }
        printf("%d. %d\n",ca++,(l+1)/2+(r+1)/2);
    }
}
