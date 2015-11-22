#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#define pb push_back
using namespace std;
int main(){
    int n,k,tmp;
    char op;
    while(scanf("%d%d%*c",&n,&k)!=EOF){
        vector<int>H;
        for(int i=0;i<k;++i){
            scanf("%c %d%*c",&op,&tmp);
            H.pb(tmp);
        }
        n-=k;
        make_heap(H.begin(),H.end(), greater<int>() );
        while(n--){
            int top=*(H.begin());
            do{op=getchar();}while(op!='I'&&op!='Q');
            if(op == 'I'){
                scanf("%d%*c",&tmp);
                if(tmp>top){
                    pop_heap(H.begin(),H.end(), greater<int>() );
                    H.pop_back();
                    H.pb(tmp);
                    push_heap(H.begin(),H.end(), greater<int>() );
                }
            }
            else printf("%d\n",top);
        }
    }
}
