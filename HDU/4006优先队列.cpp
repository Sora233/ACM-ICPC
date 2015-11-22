#include<cstdio>
#include<queue>
#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;
int main(){
    int n,k,tmp;
    char op;
    while(scanf("%d%d%d",&n,&k)!=EOF)
    {
        priority_queue<int,vector<int>, greater<int> > q;
        for(int i=0;i<k;++i){
            scanf("%c %d%*c",&op,&tmp);
            q.push(tmp);
        }
        n-=k;
        while(n--){
            scanf("%c%*c",&op);
            if(op=='I'){
                scanf("%d%*c",&tmp);
                if(tmp>q.top()){
                    q.pop();
                    q.push(tmp);
                }
            }
            else printf("%d\n",q.top());
        }
    }
}
