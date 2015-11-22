#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
int main(){
    int T;
    char ss[105];
    const char tar[] = "anniversary";
    scanf("%d%*c", &T);
    while( T-- ){
        scanf("%s", ss);
        int cot = 0, cnt = 0, flag = 0;
        for(int i = 0; ss[i] && cnt <= 10; ++i){
            if(cnt <= 10 && ss[i] == tar[cnt]){
                cnt += 1;
                if( flag == 0 ){
                    cot += 1;
                    flag = 1;
                }
            }
            else flag = 0;
        }
        if( cot <= 3 && cnt > 10) puts("YES");
        else puts("NO");
    }
}
