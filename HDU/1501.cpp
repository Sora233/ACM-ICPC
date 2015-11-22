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
char s1[250],s2[250],s3[500];
int main(){
    int T,ca=1;
    scanf("%d%*c",&T);
    while(scanf("%s%s%s",s1,s2,s3)!=EOF){
        int len1=strlen(s1),len2=strlen(s2),len3=strlen(s3);
        int cort1=0,cort2=0,cort3=0;
        for(cort3=0;cort3<len3;){
            if(s1[cort1]==s3[cort3]) ++cort1,++cort3;
            else if(s2[cort2]==s3[cort3]) ++cort2,++cort3;
            else break;
        }
        printf("Date set %d: ",ca++);
        printf("%s\n",cort3==len3?"yes":"no");
    }
}
