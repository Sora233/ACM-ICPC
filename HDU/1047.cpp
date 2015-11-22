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
char a[205];
int num[105][205];
void println(int n[]){
    int len=n[0],i=len;
    for(i=len;i>=1;--i) if(n[i]) break;
    if(i==0) printf("0");
    else for(;i>=1;--i) printf("%d",n[i]);
    printf("\n");
}
void add(int a[],int b[]){ //b¼Óµ½a
    int lena=a[0],lenb=b[0],len=max(lena,lenb);
    for(int i=1;i<=len;++i){
        a[i]+=b[i];
        if(a[i]>9) a[i]-=10,a[i+1]+=1;
    }
    for(int i=len+1;i>=0;--i){
        if(a[i]) { a[0]=i; break;}
    }
}
int main(){
    int T;
    scanf("%d%*c",&T);
    while(T--){
        int co=0;
        while(scanf("%s",a)!=EOF){
            if(a[0]=='\n') continue;
            else if(a[0]=='0') break;
            int len=strlen(a);
            for(int i=len-1;i>=0;--i) num[co][len-i]=a[i]-'0';
            num[co++][0]=len;
        }
        if(co==1){ println(num[0]); continue; }
        int ans[205]={0};
        for(int i=0;i<co;++i){
            add(ans,num[i]);
        }
        println(ans);
        if(T) printf("\n");
    }
}
