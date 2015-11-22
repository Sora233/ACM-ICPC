#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
char s[105];
int flag;
int len;
bool isParl(char s[]){
    for(int top = 0, tail = len -1; s[top]; ++top, --tail){
        if( s[top] != s[tail] ) return 0;
    }
    return 1;
}
void dfs(int pos){
    if(pos == len) {
        if( !isParl(s) ) flag = 1;
        return;
    }
    if(s[pos] != '?') {
        dfs(pos+1);
        if(flag) return;
    }
    else {
        for(char i = 'a'; i <= 'z'; ++i){
            s[pos] = i;
            dfs(pos+1);
            if(flag) return;
            s[pos] = '?';
        }
    }
}
int main(){
    while( scanf("%d%*c", &len) != EOF ){
        scanf("%s", s);
        for(int i = 0; s[i]; ++i){
            if(s[i] == '?') {
                flag = 0;
                dfs(i);
                break;
            }
        }
        if( isParl(s) ) puts("QwQ");
        else puts(s);
    }
}
