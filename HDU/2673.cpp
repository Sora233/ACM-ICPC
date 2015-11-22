#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<string>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
int num[10005];
int main(){
    int n,i,j;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;++i) scanf("%d",&num[i]);
        sort(num,num+n);
        for(i=0,j=n-1;i<j;++i,--j){
            if(!i) printf("%d %d",num[j],num[i]);
            else printf(" %d %d",num[j],num[i]);
        }
        if(i==j) printf(" %d",num[i]);
        printf("\n");
    }
}
